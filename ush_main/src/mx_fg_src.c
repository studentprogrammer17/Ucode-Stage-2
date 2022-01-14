#include "ush.h"

typedef struct {
    pid_t pid;
    char pname[1024];
    int id;
} proc;

typedef struct node {
    proc data;
    struct node* next;
} node;

pid_t FG_CHILD_PID;
char FG_CHILD_PNAME[1024];
node* processes;

bool mx_fg(int n, char* argv[]);

void mx_fg_src(int argc, char* argv[]) {
    if (argc > 0 && strcmp(argv[argc-1], "&") == 0) {
        argc--;
    }

    if (argc != 1) {
        fprintf(stderr, "fg: job not found %s\n",argv[1]);
        return;
    }

    int job_num = strtol(argv[0], NULL, 0);
    if (job_num <= 0) {
        fprintf(stderr, "fg: no current job\n");
        return;
    }

    mx_fg(job_num,argv);
}


node* insert_tail(node* head, proc data) {
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;

    if (head == NULL) {
        return new;
    }

    node* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = new;
    return head;
}

node* delete_node_by_pid(node* head, pid_t pid) {
    if (head == NULL) {
        return NULL;
    }

    if (head->data.pid == pid) {
        node* temp = head->next;
        free(head);
        return temp;
    }

    node* cur = head->next;
    node* prev = head;

    while (cur != NULL) {
        if (cur->data.pid == pid) {
            prev->next = cur->next;
            free(cur);
            return head;
        }
        prev = cur;
        cur = cur->next;
    }
    return head;
}

proc* get_data_by_pid(node* head, pid_t pid) {
    int i = 0;
    while (head != NULL) {
        i++;
        if (head->data.pid == pid) {
            head->data.id = i;
            return &(head->data);
        }
        head = head->next;
    }
    return NULL;
}

proc* get_data_by_id(node* head, int id) {
    int i = 0;
    while (head != NULL) {
        i++;
        if (i == id) {
            head->data.id = i;
            return &(head->data);
        }
        head = head->next;
    }
    return NULL;
}
 
proc make_proc (pid_t pid, char* pname) {
    proc p;
    p.id = -1;
    p.pid = pid;
    strcpy(p.pname, pname);
    return p;
}

int store_process(pid_t pid, char* temp) {

    processes = insert_tail(processes, make_proc(pid, temp));
    
    proc* val = get_data_by_pid(processes, pid);
    if (val != NULL)
        return val->id;
    else
        return -1;
}

bool mx_fg(int n,char *argv[]) {
    proc* p = get_data_by_id(processes, n);

    if (p == NULL) {
        fprintf(stderr, "fg: %s no such job\n", argv[1]);
        return false;
    }

    pid_t child_pid = p->pid;
    
    printf("[%d] %s %d resumed\n", n, p->pname, p->pid);

    FG_CHILD_PID = child_pid;
    strcpy(FG_CHILD_PNAME, p->pname);

    // process list only stores background processes
    processes = delete_node_by_pid(processes, child_pid);

    // protect shell against signals for illegal use of stdin and stdout
    signal(SIGTTIN, SIG_IGN);
    signal(SIGTTOU, SIG_IGN);

    // It is already a separate group
    // make the child's process group the foreground process group
    tcsetpgrp(STDIN_FILENO, child_pid);
    // TODO: Error handling here

    // ask child to continue
    kill(child_pid, SIGCONT);

    // wait for child
    int w_st;
    waitpid(child_pid, &w_st, WUNTRACED);

    // child is completed, now make shell the foreground process group again
    tcsetpgrp(STDIN_FILENO, getpgrp());

    // safe to end protection from signals
    signal(SIGTTIN, SIG_DFL);
    signal(SIGTTOU, SIG_DFL);
    
    // if the child was just stopped, store it in the process list again
    if (WIFSTOPPED(w_st)) {
        // IT WAS STOPPED, NOT TERMINATED
        int child_id = store_process(FG_CHILD_PID, FG_CHILD_PNAME);
        printf("[%d] %s %d suspended\n", child_id, FG_CHILD_PNAME, FG_CHILD_PID);
    }

    // no foreground process
    FG_CHILD_PID = -1;
    FG_CHILD_PNAME[0] = '\0';

    return (WIFEXITED(w_st) && WEXITSTATUS(w_st) == EXIT_SUCCESS);
}


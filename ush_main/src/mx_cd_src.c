#include "ush.h"


void mx_cd_src(char *argv[], char *envp[]){
    char *gdir;
    char *dir;
    char *to = NULL;
    char buf[BUFFER_LEN];
    char old_cwd[BUFFER_LEN];
    char cwd[BUFFER_LEN];

    gdir = getcwd(buf, sizeof(buf));

    dir = strcat(gdir, "/");

    mx_setenv_src(envp, dir, "PWD");

    /* *********************************** FLAGS *********************************** */
    if(strcmp(argv[1], "-P") == 0){
        if(strcmp(argv[2], "~/") == 0 || strcmp(argv[2], "~") == 0){
            getcwd(old_cwd, sizeof(old_cwd));
            setenv("OLDPWD", old_cwd, 1);

            char *str_log = getlogin();

            to = mx_strjoin("/Users/", str_log);
            
            chdir(to);

            getcwd(cwd, sizeof(cwd));
            setenv("PWD", cwd, 1);
            dir = cwd;

            mx_setenv_src(envp, dir, "PWD");
        }
        if(strncmp(argv[2], "~", 1) == 0 && strcmp(argv[2], "~") != 0 && strncmp(argv[2], "~+/", 3) != 0 && strncmp(argv[2], "~-/", 3) != 0){
            getcwd(old_cwd, sizeof(old_cwd));
            setenv("OLDPWD", old_cwd, 1);
            
            int ch_cnt = mx_strlen("~");
            int size = strlen(argv[2]);
            
            smesh(ch_cnt, size, argv[2]);
            argv[1] = strtok(argv[2], "~");
            to = strcat(dir, argv[2]);

            chdir(to);

            getcwd(cwd, sizeof(cwd));
            setenv("PWD", cwd, 1);
            dir = cwd;

            mx_setenv_src(envp, dir, "PWD");
        }
        if(strncmp(argv[2], "~+/", 3) == 0 || strncmp(argv[2], "~-/", 3) == 0){
            getcwd(old_cwd, sizeof(old_cwd));
            setenv("OLDPWD", old_cwd, 1);
            
            int ch_cnt = mx_strlen("~?/");
            int size = strlen(argv[2]);
            
            smesh(ch_cnt, size, argv[2]);

            to = strtok(argv[2], "~");
            to = strcat(dir, to);

            chdir(to); 

            getcwd(cwd, sizeof(cwd));
            setenv("PWD", cwd, 1);
            dir = cwd;

            mx_setenv_src(envp, dir, "PWD");
        }
        if(strcmp(argv[2], "/") == 0){
            getcwd(old_cwd, sizeof(old_cwd));
            setenv("OLDPWD", old_cwd, 1);
            
            to = mx_strjoin(to, argv[2]);
            chdir(to);

            getcwd(cwd, sizeof(cwd));
            setenv("PWD", cwd, 1);
            dir = cwd;

            mx_setenv_src(envp, dir, "PWD");
        }
        if(argv[2]){
            getcwd(old_cwd, sizeof(old_cwd));
            setenv("OLDPWD", old_cwd, 1);

            to = mx_strjoin(dir, argv[2]);
            chdir(to);

            getcwd(cwd, sizeof(cwd));
            setenv("PWD", cwd, 1);
            dir = cwd;

            mx_setenv_src(envp, dir, "PWD");
        }
        
    }

    // if(strcmp(argv[1], "-") == 0){
    //     getcwd(old_cwd, sizeof(old_cwd));
    //     setenv("OLDPWD", old_cwd, 1);
    //     to = NULL;
    //     to = mx_strjoin(to, "/");
    //     chdir(to);

    //     getcwd(cwd, sizeof(cwd));
    //     setenv("PWD", cwd, 1);
    //     dir = cwd;
        
    //     mx_setenv_src(envp, dir, "PWD");
    // }

    if(strcmp(argv[1], "-") == 0){
        char *old = getenv("OLDPWD");
        chdir(old);
        setenv("PWD", old, 1);
        dir = old;
    }

    /* ***************************************************************************** */

    if(strcmp(argv[1], "-P") != 0 || strcmp(argv[1], "-s") != 0 || strcmp(argv[1], "-") != 0){
        if(strcmp(argv[1], "~/") == 0 || strcmp(argv[1], "~") == 0){
            getcwd(old_cwd, sizeof(old_cwd));
            setenv("OLDPWD", old_cwd, 1);
        
            char *str_log = getlogin();

            to = mx_strjoin(to, "/Users/");
            to = mx_strjoin(to, str_log);
            
            chdir(to);

            getcwd(cwd, sizeof(cwd));
            setenv("PWD", cwd, 1);
            dir = cwd;

            mx_setenv_src(envp, dir, "PWD");
        }
        if(strncmp(argv[1], "~", 1) == 0 && strcmp(argv[1], "~") != 0 && strncmp(argv[1], "~+/", 3) != 0 && strncmp(argv[1], "~-/", 3) != 0){
           
            getcwd(old_cwd, sizeof(old_cwd));
            setenv("OLDPWD", old_cwd, 1);
            
            int ch_cnt = mx_strlen("~");
            int size = strlen(argv[1]);
            
            smesh(ch_cnt, size, argv[1]);
    
            argv[1] = *mx_strsplit(argv[1], '~');
            if(strcmp(dir, "//") == 0){
                to = NULL;
                
                to = mx_strjoin(to, "/");

                to = mx_strjoin(to, argv[1]);
              
                

                chdir(dir);
                to = dir;

                setenv("PWD", to, 1);
                dir = to;

               
            }
            else{
                to = mx_strjoin(to, dir);

                to = mx_strjoin(to, argv[1]);

                chdir(to);

                getcwd(cwd, sizeof(cwd));
                setenv("PWD", cwd, 1);
                dir = cwd;

            }
            

            mx_setenv_src(envp, dir, "PWD");
        }
        if(strncmp(argv[1], "~+/", 3) == 0 || strncmp(argv[1], "~-/", 3) == 0){
            getcwd(old_cwd, sizeof(old_cwd));
            setenv("OLDPWD", old_cwd, 1);
            
            int ch_cnt = mx_strlen("~?/");
            int size = strlen(argv[1]);
            
            smesh(ch_cnt, size, argv[1]);
            argv[1] = *mx_strsplit(argv[1], '~');
            if(strcmp(dir, "//") == 0){
                to = NULL;
                
                to = mx_strjoin(to, "/");

                to = mx_strjoin(to, argv[1]);
              
                

                chdir(dir);
                to = dir;

                setenv("PWD", to, 1);
                dir = to;

               
            }
            else{
                 
                to = strcat(dir, argv[1]);

                chdir(to); 

                getcwd(cwd, sizeof(cwd));
                setenv("PWD", cwd, 1);
                dir = cwd;

            }
            
            mx_setenv_src(envp, dir, "PWD");
        }
        if(strcmp(argv[1], "/") == 0){
            getcwd(old_cwd, sizeof(old_cwd));
            setenv("OLDPWD", old_cwd, 1);
            
            to = mx_strjoin(to, argv[1]);
            chdir(to);

            getcwd(cwd, sizeof(cwd));
            setenv("PWD", cwd, 1);
            dir = cwd;

            mx_setenv_src(envp, dir, "PWD");

        }
        if(argv[1] && strcmp(argv[1], "/") != 0){
            getcwd(old_cwd, sizeof(old_cwd));
            setenv("OLDPWD", old_cwd, 1);
            to = mx_strjoin(dir, argv[1]);
            chdir(to);

              
                getcwd(cwd, sizeof(cwd));
                setenv("PWD", cwd, 1);
                
                dir = cwd;
            
                mx_setenv_src(envp, dir, "PWD");
        }
        
    }

    
   
    
   
}


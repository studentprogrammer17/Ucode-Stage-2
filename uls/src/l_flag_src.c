#include "uls.h"

int rozryad_chislo(int n) {
	int i = 0;

	while (n > 0)
	{
		++i;
		n /= 10;
	}
	
	return i;
}

void l_flag_src(DIR *dp, char *arg,bool flag_file, char **names) {
	struct group *grp = NULL;
    struct dirent *entry = NULL;
    struct stat statbuf;
    struct passwd pwent;
    char n_buf[1024];


	
    if(flag_file == true) {
    	lstat(arg,&statbuf);

		// тута адская херь из тернарников, chmod
		mx_printstr((S_ISDIR(statbuf.st_mode)) ? "d" : "-");
		mx_printstr((statbuf.st_mode & S_IRUSR) ? "r" : "-");
		mx_printstr( (statbuf.st_mode & S_IWUSR) ? "w" : "-");
		mx_printstr( (statbuf.st_mode & S_IXUSR) ? "x" : "-");
		mx_printstr( (statbuf.st_mode & S_IRGRP) ? "r" : "-");
		mx_printstr( (statbuf.st_mode & S_IWGRP) ? "w" : "-");
		mx_printstr( (statbuf.st_mode & S_IXGRP) ? "x" : "-");
		mx_printstr( (statbuf.st_mode & S_IROTH) ? "r" : "-");
		mx_printstr( (statbuf.st_mode & S_IWOTH) ? "w" : "-");
		mx_printstr( (statbuf.st_mode & S_IXOTH) ? "x" : "-");

		// узнаем имя юзера
		struct passwd *pw = getpwuid(statbuf.st_uid);
	    char *name = pw ? mx_strdup(pw->pw_name) : mx_itoa(statbuf.st_uid);
	    pwent.pw_name = name;

    	int i = 0;
		for(; arg[i] != '\0'; i++) {
			n_buf[i] = arg[i];
		}
		n_buf[i] = '/';
		i++;
		for(int j = 0; arg[j] != '\0'; j++) {
			n_buf[i] = arg[j];
			i++;
		}
		n_buf[i] = '\0';

		stat(n_buf, &statbuf);

		mx_printstr(" ");
		mx_printint(statbuf.st_nlink);
		mx_printstr(" ");
		mx_printstr(pwent.pw_name);
		mx_printstr("  ");

		// вывод группы
		if ((grp = getgrgid(statbuf.st_gid)) == NULL) mx_printstr(mx_itoa(statbuf.st_gid));
		else mx_printstr(grp->gr_name);

		mx_printstr(" ");

		mx_printint(statbuf.st_size);
		mx_printstr(" ");

		// время ( нам не нужно выводить день недели, поэтмоу мы сокращаем массив и также обрезаем его с конца до вывода минут)
		char *time_str_year = ctime(&statbuf.st_mtime);
		
		mx_memmove(time_str_year, time_str_year+20, mx_strlen (time_str_year+1) + 1);
		time_str_year[mx_strlen(time_str_year)-1] = '\0';

		char *year = mx_strdup(time_str_year);
		if(mx_atoi(time_str_year) <= 2020) {
			char *time_str_time = ctime(&statbuf.st_mtime);
			mx_memmove(time_str_time, time_str_time+4, mx_strlen (time_str_time+1) + 1);
			time_str_time[mx_strlen(time_str_time)-15] = '\0';
			mx_printstr(time_str_time);
			mx_printstr("  ");
			mx_printstr(year);
		}
		else {
			char *time_str_time_2 = ctime(&statbuf.st_mtime);
			mx_memmove(time_str_time_2, time_str_time_2+4, mx_strlen (time_str_time_2+1) + 1);
			time_str_time_2[mx_strlen(time_str_time_2)-9] = '\0';
			mx_printstr(time_str_time_2);
		}

		mx_printstr(" ");
		mx_printstr(arg);
		mx_printchar('\n');
	}
	else {
		// prints total block of something shit i really dont know that the hell is this
		mx_printstr("total ");
		int total = mx_get_total(arg);
		mx_printint(total);
		mx_printstr("\n");

		if(mx_strcmp(arg,".") == 0) {
			char **names = mx_get_names(entry,dp, false);
			mx_fort_files_first(names);

			for(int k = 0; names[k] != NULL; k++) { 
		    	lstat(names[k],&statbuf);
			
				// скип хуйню если файл начинается с точек или если она тама стоят
				if(names[k][0] == '.') {
					continue;
				}

				// тута адская херь из тернарников, chmod
			mx_printstr((S_ISDIR(statbuf.st_mode)) ? "d" : "-");
			mx_printstr((statbuf.st_mode & S_IRUSR) ? "r" : "-");
			mx_printstr( (statbuf.st_mode & S_IWUSR) ? "w" : "-");
			mx_printstr( (statbuf.st_mode & S_IXUSR) ? "x" : "-");
			mx_printstr( (statbuf.st_mode & S_IRGRP) ? "r" : "-");
			mx_printstr( (statbuf.st_mode & S_IWGRP) ? "w" : "-");
			mx_printstr( (statbuf.st_mode & S_IXGRP) ? "x" : "-");
			mx_printstr( (statbuf.st_mode & S_IROTH) ? "r" : "-");
			mx_printstr( (statbuf.st_mode & S_IWOTH) ? "w" : "-");
			mx_printstr( (statbuf.st_mode & S_IXOTH) ? "x" : "-");

				// узнаем имя юзера
				struct passwd *pw = getpwuid(statbuf.st_uid);
				char *name = pw ? mx_strdup(pw->pw_name) : mx_itoa(statbuf.st_uid);
				pwent.pw_name = name;

				// Это у нас для опрежеления размера
				int i = 0;
				for(; arg[i] != '\0'; i++) {
					n_buf[i] = arg[i];
				}
				n_buf[i] = '/';
				i++;
				for(int j = 0; names[j] != '\0'; j++) {
					n_buf[i] = *names[j];
					i++;
				}
				n_buf[i] = '\0';

				stat(n_buf, &statbuf);

				// int c = rozryad_chislo(statbuf.st_nlink);
				// for(int i = 0;i < c; i++) {
				// 	mx_printstr(" ");
				// 	mx_printint(statbuf.st_nlink);
				// }
				mx_printstr(" ");
			
				mx_printint(statbuf.st_nlink);
				mx_printstr(" ");
				mx_printstr(pwent.pw_name);
				mx_printstr("  ");

				//  группа
				if ((grp = getgrgid(statbuf.st_gid)) == NULL) mx_printstr(mx_itoa(statbuf.st_gid));
				else mx_printstr(grp->gr_name);

				mx_printstr("  ");
				mx_printint(statbuf.st_size);
				mx_printstr(" ");
				
				// время
				char *time_str_year = ctime(&statbuf.st_mtime);
		
				mx_memmove(time_str_year, time_str_year+20, mx_strlen (time_str_year+1) + 1);
				time_str_year[mx_strlen(time_str_year)-1] = '\0';

				char *year = mx_strdup(time_str_year);
				if(mx_atoi(time_str_year) <= 2020) {
					char *time_str_time = ctime(&statbuf.st_mtime);
					mx_memmove(time_str_time, time_str_time+4, mx_strlen (time_str_time+1) + 1);
					time_str_time[mx_strlen(time_str_time)-15] = '\0';
					mx_printstr(time_str_time);
					mx_printstr("  ");
					mx_printstr(year);
				}
				else {
					char *time_str_time_2 = ctime(&statbuf.st_mtime);
					mx_memmove(time_str_time_2, time_str_time_2+4, mx_strlen (time_str_time_2+1) + 1);
					time_str_time_2[mx_strlen(time_str_time_2)-9] = '\0';
					mx_printstr(time_str_time_2);
				}

				mx_printstr(" ");
				mx_printstr(names[k]);
				mx_printchar('\n');
			}
		}
		else {
		for(int s = 0; names[s] != NULL; s++){
		    lstat(names[s],&statbuf);
			
			// скип хуйню если файл начинается с точек или если она тама стоят
		    if(names[s][0] == '.') {
		        continue;
			}

			// тута адская херь из тернарников, chmod
			mx_printstr((S_ISDIR(statbuf.st_mode)) ? "d" : "-");
			mx_printstr((statbuf.st_mode & S_IRUSR) ? "r" : "-");
			mx_printstr( (statbuf.st_mode & S_IWUSR) ? "w" : "-");
			mx_printstr( (statbuf.st_mode & S_IXUSR) ? "x" : "-");
			mx_printstr( (statbuf.st_mode & S_IRGRP) ? "r" : "-");
			mx_printstr( (statbuf.st_mode & S_IWGRP) ? "w" : "-");
			mx_printstr( (statbuf.st_mode & S_IXGRP) ? "x" : "-");
			mx_printstr( (statbuf.st_mode & S_IROTH) ? "r" : "-");
			mx_printstr( (statbuf.st_mode & S_IWOTH) ? "w" : "-");
			mx_printstr( (statbuf.st_mode & S_IXOTH) ? "x" : "-");

			// узнаем имя юзера
			struct passwd *pw = getpwuid(statbuf.st_uid);
		    char *name = pw ? mx_strdup(pw->pw_name) : mx_itoa(statbuf.st_uid);
		    pwent.pw_name = name;

			// Это у нас для опрежеления размера
			int i = 0;
			for(; arg[i] != '\0'; i++) {
				n_buf[i] = arg[i];
			}
			n_buf[i] = '/';
			i++;
			for(int j = 0; names[s][j] != '\0'; j++) {
				n_buf[i] = names[s][j];
				i++;
			}
			n_buf[i] = '\0';

			stat(n_buf, &statbuf);


			// int c = rozryad_chislo(statbuf.st_nlink);
			// for(int i = 0;i < c; i++) {
			// 	mx_printstr(" ");
			// 	mx_printint(statbuf.st_nlink);
			// }
			mx_printstr("  ");


			mx_printint(statbuf.st_nlink);
			mx_printstr(" ");
			mx_printstr(pwent.pw_name);
			mx_printstr("  ");

			//  группа
			if ((grp = getgrgid(statbuf.st_gid)) == NULL) mx_printstr(mx_itoa(statbuf.st_gid));
			else mx_printstr(grp->gr_name);

			mx_printstr("  ");
			mx_printint(statbuf.st_size);
			mx_printstr(" ");
			
			// время
			char *time_str_year = ctime(&statbuf.st_mtime);
	
			mx_memmove(time_str_year, time_str_year+20, mx_strlen (time_str_year+1) + 1);
			time_str_year[mx_strlen(time_str_year)-1] = '\0';

			char *year = mx_strdup(time_str_year);
			if(mx_atoi(time_str_year) <= 2020) {
				char *time_str_time = ctime(&statbuf.st_mtime);
				mx_memmove(time_str_time, time_str_time+4, mx_strlen (time_str_time+1) + 1);
				time_str_time[mx_strlen(time_str_time)-15] = '\0';
				mx_printstr(time_str_time);
				mx_printstr("  ");
				mx_printstr(year);
			}
			else {
				char *time_str_time_2 = ctime(&statbuf.st_mtime);
				mx_memmove(time_str_time_2, time_str_time_2+4, mx_strlen (time_str_time_2+1) + 1);
				time_str_time_2[mx_strlen(time_str_time_2)-9] = '\0';
				mx_printstr(time_str_time_2);
			}
			mx_printstr(" ");
			mx_printstr(names[s]);
			mx_printchar('\n');
		}
		closedir(dp);
		}
	}
}


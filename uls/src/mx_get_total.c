#include "uls.h"

int mx_get_total(char* directory) {
   int size = 0;

   DIR *d;
   struct dirent *dir;
   struct stat fileStat;
   d = opendir(directory);
   if (d) {
       while ((dir = readdir(d)) != NULL) {
           if (dir->d_name[0] != '.') { // Ignore hidden files
               // Create the path to stat
               char info_path[256];
               mx_strcpy(info_path, directory);
               if (directory[mx_strlen(directory) - 1] != '/')
                   mx_strcat(info_path, "/");
               mx_strcat(info_path, dir->d_name);

               stat(info_path, &fileStat);

               size += fileStat.st_blocks;
           }
       }
   }

   return size;
}


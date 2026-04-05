#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include "dir_ops.h"
#include "format.h"

void list_directory(const char *dir_path) {
  DIR *dir = opendir(dir_path);
  if (dir == NULL) {
    perror("Cannot open directory");
    return;
  }

  struct dirent *entry;
  struct stat file_stat;
  char full_path[1024];
  char time_buf[64];

  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_name[0] == '.') continue; // Skip hidden files

    snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

    if (stat(full_path, &file_stat) == -1) {
        perror("stat failed");
        continue;
    }

    print_permissions(file_stat.st_mode);
    printf("%lu ", (unsigned long)file_stat.st_nlink);

    struct passwd *pw = getpwuid(file_stat.st_uid);
    struct group  *gr = getgrgid(file_stat.st_gid);
    printf("%s %s ", pw ? pw->pw_name : "unknown", gr ? gr->gr_name : "unknown");

    printf("%5lld ", (long long)file_stat.st_size);

    format_time(file_stat.st_mtime, time_buf, sizeof(time_buf));
    printf("%s ", time_buf);

    printf("%s\n", entry->d_name);
  }

  closedir(dir);
}

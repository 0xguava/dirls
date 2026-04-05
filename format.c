#include <stdio.h>
#include <sys/stat.h>
#include "format.h"

void print_permissions(mode_t mode) {
  printf((S_ISDIR(mode))  ? "d" : "-");
  printf((mode & S_IRUSR) ? "r" : "-");
  printf((mode & S_IWUSR) ? "w" : "-");
  printf((mode & S_IXUSR) ? "x" : "-");
  printf((mode & S_IRGRP) ? "r" : "-");
  printf((mode & S_IWGRP) ? "w" : "-");
  printf((mode & S_IXGRP) ? "x" : "-");
  printf((mode & S_IROTH) ? "r" : "-");
  printf((mode & S_IWOTH) ? "w" : "-");
  printf((mode & S_IXOTH) ? "x" : "-");
  printf(" ");
}

void format_time(time_t mod_time, char *buffer, size_t buf_size) {
  struct tm *tm_info = localtime(&mod_time);
  strftime(buffer, buf_size, "%b %d %H:%M", tm_info);
}

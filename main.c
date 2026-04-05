#include "dir_ops.h"

int main(int argc, char *argv[]) {
  // Default to current directory if no argument is passed
  const char *dir_path = (argc > 1) ? argv[1] : ".";
  
  list_directory(dir_path);
  
  return 0;
}

#ifndef FORMAT_H
#define FORMAT_H

#include <sys/types.h>
#include <time.h>

// Declarations for formatting functions
void print_permissions(mode_t mode);
void format_time(time_t mod_time, char *buffer, size_t buf_size);

#endif // FORMAT_H

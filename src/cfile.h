#ifndef __CFILE__
#define __CFILE__

#include <stdlib.h>

typedef struct {
    char **files;
    size_t count;
} cfile_dir_t;

cfile_dir_t get_files_names(const char *path);
void cfile_free(cfile_dir_t *ctx);

#endif

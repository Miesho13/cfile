#include <dirent.h>
#include <sys/types.h>
#include <regex.h>
#include <string.h>
#include "cfile.h"

cfile_dir_t get_files_names(const char *path) {
    cfile_dir_t result = {0};

    DIR *dir = opendir(path);
    struct dirent *entry = NULL;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 
                || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        result.files = realloc(result.files, sizeof(char *)*(result.count + 1));
        result.files[result.count] = strdup(entry->d_name);
        result.count++;
    }

    closedir(dir);
    return result;
}


cfile_dir_t find_files(const char *path, const char *pattern) {
    cfile_dir_t result = {0};
    
    DIR *dir = opendir(path);
    struct dirent *entry = NULL;
    
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED | REG_NOSUB);

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 
                || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        result.files = realloc(result.files, sizeof(char *)*(result.count + 1));
        result.files[result.count] = strdup(entry->d_name);
        result.count++;
    }

    closedir(dir);
    return result;
}

void cfile_struct_free(cfile_dir_t *ctx) {
    free(ctx->files);
    ctx->count = 0;
}

#include <stdlib.h>
#include <stdio.h>
#include "cfile.h"

int main() {
    cfile_dir_t files = get_files_names(".");

    for (int i = 0; i < files.file_count; i++) {
        printf("%s\n", files.files[i]);
    }

    return 0;
}

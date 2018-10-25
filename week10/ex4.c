#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <libgen.h>
#include <sys/stat.h>
#include <sys/types.h>

int NAME_MAX = 10;
int dir_len = 3;

int main() {
    DIR *dir;
    struct dirent *dp;
    struct dirent *dp2;
    struct stat buff;
    struct stat inner_buff;
    char *path = malloc(dir_len + 1 + NAME_MAX);
    strcpy(path, "tmp/");

    if ((dir = opendir("tmp")) == NULL) {
        perror("Cannot open tmp");
        exit(1);
    }

    long unsigned *inodes = malloc(sizeof(long unsigned) * 10);
    int *file_count = malloc(sizeof(int) * 10);
    char ***names = malloc(sizeof(char**) * 10);
    for (int i = 0; i < 10; i++) {
        names[i] = malloc(sizeof(char*) * 10);
        file_count[i] = 0;
    }

    int i = 0;
    while ((dp = readdir (dir)) != NULL) {
        int found = 0;
        for (int j = 0; j < 10 && found == 0; j++) {
            if (inodes[j] == dp->d_ino) {
                found = 1;
                names[j][file_count[j]] = dp->d_name;
                file_count[j]++;
            }
        }

        if (found == 0) {
            inodes[i] = dp->d_ino;
            names[i][file_count[i]] = dp->d_name;
            file_count[i]++;
            i++;
        }
    }

    for (int i = 0; i < 10; i++) {
        if (file_count[i] > 1) {
            printf("%lu\n", inodes[i]);
            for (int j = 0; j < file_count[i]; j++) {
                printf("-- %s\n", names[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    struct stat fileSize;
    DIR *dirPtr; 
    struct dirent *entryPtr;
    if (argc < 2) {
        printf("Usage: argument (filename) expected \n");
        exit(1);
    }

    if (stat(argv[1], &fileSize) < 0) {
        perror("Program error:");
        exit(1);
    }

    dirPtr = opendir ("."); 
    while ((entryPtr = readdir (dirPtr))) {
        if (stat(entryPtr->d_name, &fileSize) == 0) {
            printf ("%-20s\tnode value is: %lu\tUser ID: %d\tGroup ID: %d\n", entryPtr->d_name, fileSize.st_ino, fileSize.st_uid, fileSize.st_gid); 
        }
    }
    closedir (dirPtr);

    return 0;
}
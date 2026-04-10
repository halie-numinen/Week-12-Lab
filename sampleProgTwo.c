#include <stdio.h>
#include <dirent.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <errno.h> 

int main() {
    DIR *dirPtr; 
    struct dirent *entryPtr;
    struct stat fileSize;
    dirPtr = opendir ("."); 
    while ((entryPtr = readdir (dirPtr))) {
        if (stat(entryPtr->d_name, &fileSize) == 0) {
            printf ("%-20s\t%ld\n", entryPtr->d_name, fileSize.st_size); 
        }
    }
    closedir (dirPtr); 
    return 0; 
}

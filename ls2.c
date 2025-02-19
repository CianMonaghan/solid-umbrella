#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ls2.h"


/**
 * Builds the path from the inputed path name
 * and puts it into a path string
 */
void buildPath(char* pathName[], char* path[]) {
    struct stat*restrict pathStat;
    stat(pathName, pathStat);
    while(S_ISREG(pathStat->st_mode)){//isn't normal file
        struct dirent pathDirent;
        DIR* pathDIR = opendir(pathName);
        readdir(pathDIR);
        if(S_ISDIR(pathStat->st_mode)){//is dir
            strcat(path, INDENT);
            strcat(path, pathDirent.d_name);
            buildPath(pathDirent.d_name, path); //recursion
        }
        //i know this is bad form
        int leafSize = pathStat->st_size;
        strcat(path, INDENT);
        strcat(path, pathDirent.d_name);
        strcat(path, " (Size: ");
        strcat(path, leafSize);
        strcat(path, " bytes)");
        closedir(pathDIR);
        //this probably doesn't work
    }

} 

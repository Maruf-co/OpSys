#include <stdio.h>
#include <dirent.h>
int main(){
    struct dirent *files;
    DIR *dir = opendir(".");
    while ((files = readdir(dir)) != NULL)
        if(files->d_name[0] != '.')
            printf("%s ", files->d_name);

    printf("\n");
    closedir(dir);
    return 0;
}

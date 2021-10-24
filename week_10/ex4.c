#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

int main() {
    DIR* dirp = opendir("../week_10/tmp");
    struct stat buf;
    struct dirent  *file;
    char a[10][10];
    int b[100];
    int i = 0, j, k;
    while ((file = readdir(dirp)) != NULL){
        char str[80];
        strcpy(str, "../week_10/tmp/");
        strcat(str, file->d_name);
        stat(str, &buf);
        nlink_t count = buf.st_nlink;
        if (count >= 2){
            strcpy(a[i], file->d_name);
            ino_t inode = buf.st_ino;
            b[i] = inode;
            i++;
        }
    }
    printf("File -- Hard Links\n");
    for (j = 0; j < i; ++j){
        int tmp = b[j];
        char str[80];
        strcpy(str, "");
        int c = 0;
        for (k = 0; k < i; ++k){
            if (b[k] == tmp && tmp !=-1){
                strcat(str,a[k]);
                strcat(str,", ");
                c++;
                b[k] = -1;
            }
        }
        if (c >= 2 && tmp != -1){
            printf("file1 -- ");
            printf("%s ", str);
            printf("\n");
            printf("link1 -- ");
            printf("%s ",str);
            printf("\n");
        }
        b[j] = -1;

    }
}

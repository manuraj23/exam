#include<stdio.h>
#include<dirent.h>

int main() {
DIR *directory;
struct dirent *entry;

directory=opendir(".");
if(directory==NULL) {
perror("Unable to open directory");
return 1;
}

printf("Contents of current directory:\n");
while((entry=readdir(directory))!=NULL) {
printf("%s\n",entry->d_name);
}

closedir(directory);

return 0;
}

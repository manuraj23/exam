#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    const char *dirname = "NewDirectory";
    // Creating a new directory named "NewDirectory" with full permissions for owner, group, and others
    mkdir(dirname, 0777);
    return 0;
}

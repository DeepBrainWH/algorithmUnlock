#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int fd = open(argv[1], O_CREAT | O_RDWR, 0777);
    if (fd < 0) {
        printf("create file %s failure\n", argv[1]);
        return -1;
    }
    printf("create file %s sucess !\n", argv[1]);
    return 0;
}
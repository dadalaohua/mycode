#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>

#define DEV_NAME "/dev/My_reverse"

int main(int argc, char **argv)
{
    int i   = 0;
    int fd  = open(DEV_NAME, O_RDWR);
    
    if(fd < 0)
    {
        perror("Open DEV_NAME Failed!\n");
        exit(1);
    }
 
    i = write(fd, argv[1], strlen(argv[1]));
    if(!i){
        perror("Write DEV_NAME Failed!\n");
        exit(1);
    }
    
    i = read(fd, argv[1], strlen(argv[1]));
    if(!i){
        perror("Read DEV_NAME Failed!\n");
        exit(1);
    }
    printf("Read: %s\n", argv[1]);
    
    close(fd);
    
    return 0;
}
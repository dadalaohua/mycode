#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>

#define DEV_NAME "/dev/skel%d"

int main(int argc, char **argv)
{
    int fd  = open(DEV_NAME, O_RDWR);
    int dat = 0;
    int i   = 0;
    
    if(fd < 0)
    {
        perror("Open DEV_NAME Failed!\n");
        exit(1);
    }
 
    i = read(fd, &dat, 1);
    if(!i){
        perror("Read DEV_NAME Failed!\n");
        exit(1);
    }
    
    
    dat = 0;
    i = write(fd, &dat, 1);
    if(!i){
        perror("Write DEV_NAME Failed!\n");
        exit(1);
    }
    
    // i = ioctl(fd, NULL, NULL);
    // if(!i){
        // perror("ioctl DEV_NAME Failed!\n");
        // exit(1);
    // }
    
    close(fd);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>

#define DEV_NAME "/dev/My_proc"

int main(int argc, char **argv)
{
    int i   = 0;
    int fd  = open(DEV_NAME, O_RDWR);
    unsigned char buff[256];
    
    if(fd < 0)
    {
        perror("Open DEV_NAME Failed!\n");
        exit(1);
    }
 
    printf("read orig data from device\n");
    i = read(fd, &buff, 5);
    if(!i){
        perror("Read DEV_NAME Failed!\n");
        exit(1);
    }
    for(i = 0; i < 5; i++){
        printf("0x%02x ", buff[i]);
    }
    printf("\n");
    
    printf("write data into device\n");
    for(i = 0; i < 5; i++){
        buff[i] +=10;
    }    
    i = write(fd, &buff, 5);
    if(!i){
        perror("Write DEV_NAME Failed!\n");
        exit(1);
    }
    
    printf("read new data from device\n");
    i = read(fd, &buff, 5);
    if(!i){
        perror("Read DEV_NAME Failed!\n");
        exit(1);
    }
    for(i = 0; i < 5; i++){
        printf("0x%02x ", buff[i]);
    }
    printf("\n");
    
    // i = ioctl(fd, NULL, NULL);
    // if(!i){
        // perror("ioctl DEV_NAME Failed!\n");
        // exit(1);
    // }
    
    close(fd);
    
    return 0;
}
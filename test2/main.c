#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <linux/reboot.h>
#include <stdbool.h>
#include <getopt.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/statfs.h>
#include <sys/ioctl.h>
#include <linux/fs.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <getopt.h>
#include <fcntl.h>
#include <time.h>
#include <sys/statfs.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/reboot.h>
#include <linux/reboot.h>
#include <linux/fs.h>  

char cmd[512];

int main(int argc, char **argv)
{
    // sprintf(cmd, "ls /dev/sda1");
    // system(cmd);
    printf("-----> %s %d \n", __FUNCTION__, __LINE__); fflush(stdout);

    FILE * st;
    printf("-----> %s %d \n", __FUNCTION__, __LINE__); fflush(stdout);
    char buffer[80];
    
    printf("-----> %s %d \n", __FUNCTION__, __LINE__); fflush(stdout);
    st = popen("ls /dev/kk", "r");

    printf("-----> %s %d \n", __FUNCTION__, __LINE__); fflush(stdout);
    fgets(buffer, sizeof(buffer), st);

    printf("-----> %s %d \n", __FUNCTION__, __LINE__); fflush(stdout);
    // if(fgets(buffer, sizeof(buffer), st) == "ls: cannot access")
    // {
    //     printf("fail\n");
    // }

    printf("-----> %s %d \n", __FUNCTION__, __LINE__); fflush(stdout);
    printf("%s\n", buffer);

    printf("-----> %s %d \n", __FUNCTION__, __LINE__); fflush(stdout);
    pclose(st);

    
} 
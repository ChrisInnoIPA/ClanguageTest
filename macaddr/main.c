#include <stdio.h>    //printf
#include <string.h>   //strncpy
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>   //ifreq
#include <unistd.h>   //close
#include <stdlib.h>
#include <sys/types.h>
#include <linux/reboot.h>
#include <stdbool.h>
#include <getopt.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/statfs.h>
#include <sys/ioctl.h>
#include <linux/fs.h>
#include <time.h>

/*-----------------------------------------------------------------------------------------------------------*/
unsigned long long get_disk_length_by_cmd(char *disk)
{
    unsigned long long bytes = 0;

    int fd, ret = 0;

    fd  = open(disk, O_RDONLY | O_NONBLOCK);
    ret = ioctl(fd, BLKGETSIZE64, &bytes);
    close(fd);

    if(ret != 0)
        printf("Fail !! \n");

    return bytes;
}
/*-----------------------------------------------------------------------------------------------------------*/

unsigned long long get_cpu_num(char *cpu)
{
    unsigned long long bytes = 0;

    int fd, ret = 0;

    fd  = open(cpu, O_RDONLY | O_NONBLOCK);
    ret = ioctl(fd, BLKGETSIZE64, &bytes);
    close(fd);

    if(ret != 0)
        printf("Fail !! \n");

    return bytes;
}
/*-----------------------------------------------------------------------------------------------------------*/
 
int main()
{
    int fd;
    struct ifreq ifr;
    char *iface = "eth0";
    unsigned char *mac;
 
    fd = socket(AF_INET, SOCK_DGRAM, 0);
 
    ifr.ifr_addr.sa_family = AF_INET;
    strncpy(ifr.ifr_name , iface , IFNAMSIZ-1);
 
    ioctl(fd, SIOCGIFHWADDR, &ifr);
 
    close(fd);
 
    mac = (unsigned char *)ifr.ifr_hwaddr.sa_data;
 
    //display mac address
    printf("Mac : %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n" , mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
 

    int cpu = ("Capacity = %.2f GB \n", get_cpu_num("/dev/mmcblk0p1") / 1024.0 / 1024.0 / 1024.0);

    return 0;
}
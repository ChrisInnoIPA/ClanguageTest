#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/statfs.h>
#include <sys/ioctl.h>
#include <linux/fs.h>

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


int main(int argc, char const *argv[])
{

//     struct statfs diskInfo = { 0 };
	
// 	statfs("/", &diskInfo);
// 	unsigned long long blocksize = diskInfo.f_bsize;	//每个block里包含的字节数
// 	unsigned long long totalsize = blocksize * diskInfo.f_blocks; 	//总的字节数，f_blocks为block的数目
// 	printf("Total_size = %llu B = %llu KB = %llu MB = %llu GB\n", 
// 		totalsize, totalsize>>10, totalsize>>20, totalsize>>30);
	
// 	unsigned long long freeDisk = diskInfo.f_bfree * blocksize;	//剩余空间的大小
// 	unsigned long long availableDisk = diskInfo.f_bavail * blocksize; 	//可用空间大小
// 	printf("Disk_free = %llu MB = %llu GB\nDisk_available = %llu MB = %llu GB\n", 
// 		freeDisk>>20, freeDisk>>30, availableDisk>>20, availableDisk>>30);


    //printf("Capacity = %.2f GB \n", get_disk_length_by_cmd("/dev/mmcblk0p1") / 1024.0 / 1024.0 / 1024.0);
    //printf("Capacity = %.2f GB \n", get_disk_length_by_cmd("/dev/mmcblk2p2") / 1024.0 / 1024.0 / 1024.0);

    int mmcblk0p1 = ("Capacity = %.2f GB \n", get_disk_length_by_cmd("/dev/mmcblk0p1") / 1024.0 / 1024.0 / 1024.0);
    int mmcblk2p2 = ("Capacity = %.2f GB \n", get_disk_length_by_cmd("/dev/mmcblk2p2") / 1024.0 / 1024.0 / 1024.0);

    if(mmcblk2p2 < mmcblk0p1)
    {
        printf("No Back\n");
    }
	
	return 0;
}
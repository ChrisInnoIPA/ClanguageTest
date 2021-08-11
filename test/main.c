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


int main(int argc, char **argv)
{
    // char szContent[10] = {0};
    // FILE * pFile;
    // pFile = fopen("./log.txt", "w");

    // if(pFile = NULL)
    // {
    //     fwrite("hello", 1, strlen("hello"), pFile);
    //     fclose (pFile);
    // }

    FILE *f = fopen("log.txt", "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    /* print some text */
    const char *text = "Write this to the file";
    fprintf(f, "Some text: %s\n", text);

    /* print integers and floats */
    int i = 1;
    float py = 3.1415927;
    fprintf(f, "Integer: %d, float: %f\n", i, py);

    /* printing single chatacters */
    char c = 'A';
    fprintf(f, "A character: %c\n", c);

    fclose(f);
} 
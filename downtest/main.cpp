#include <stdio.h>
#include <curl/curl.h>
//#include <curl/types.h>
#include <curl/easy.h>
#include <string>
#include <stdlib.h>

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

#include <cstring>
#include <fstream>	// std::ifstream, std::ofstream
#include <iostream>
#include <unistd.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

// static void show_usage(char *name)
// {
//     printf("Syntax: %s [-option ...] \n", name);
//     printf("Sample: %s -d -t /home/picture.jpg \n", name);
//     printf("Option:\n");
//     printf("  -d : download \n");
//     printf("  -t : path and file name \n");
// }

// FILE *f = NULL;

// enum
// {
//     MODE_DOWN     = 0,
//     MODE_RECOVERY,
// };

// typedef struct
// {
//     int  mode;
//     //char source[64];
//     char target[64];
// } DOWNLOAD_INFO;

// static const struct option long_opt[] =
// {
//     { "mode", 1, NULL, 'd' },
//     { NULL,   0, NULL, '0' },
// };

// int main(int argc, char **argv) {
// printf("------>%s %d \n", __FUNCTION__, __LINE__); fflush(stdout);
// 	DOWNLOAD_INFO info;
// 	int opt;
// 	memset(&info, 0, sizeof(DOWNLOAD_INFO));
// 	info.mode = -1;
// printf("------>%s %d \n", __FUNCTION__, __LINE__); fflush(stdout);
// 	if (argc < 2)
// 	{
//     	show_usage(argv[0]);
//     	return 0;
// 	}
// printf("------>%s %d \n", __FUNCTION__, __LINE__); fflush(stdout);
// 	// const char *SelMode = "Please entery path and file name";
//     // fprintf(f, "Now mode: %s\n", SelMode);
// 	printf("------>%s %d \n", __FUNCTION__, __LINE__); fflush(stdout);
// 	while ((opt = getopt_long(argc, argv, "?hm:s:t:", long_opt, NULL)) != -1)
//     {
//         switch (opt)
//         {
//         case 'd':
//             //info.mode = atoi(optarg);
//             //if (info.mode < MODE_BACKUP || info.mode > MODE_RECOVERY)
//                 //info.mode = -1;
//             break;
//         case 't':
//             strcpy(info.target, optarg);
//             break;
//         case 'h':
//         case '?':
//         default:
// 		printf("------>%s %d \n", __FUNCTION__, __LINE__); fflush(stdout);
//             show_usage(argv[0]);
//             //return 0;
//         }
//     }

// 	if (info.mode == MODE_DOWN)
//     {
// 		printf("------>%s %d \n", __FUNCTION__, __LINE__); fflush(stdout);
// 		char buf[512];
// 		scanf("%s", buf);
//         const char *Download = "Download";
//         fprintf(f, "Now mode: %s\n", Download);
        
//         //PutIniKeyString("Mode", "mode", "1", "./iCover.ini");
//         //printf("Mode : Backup \n");
//     }

// 	int i = 0;
// 	argc = 3;

// 	argv[0] = "a", argv[1]="b", argv[2]="c";

// 	printf("argc = %d\n", argc);

// 	for(i=0; i!=argc; i++) {
//     	printf("argv[%d] = %s\n", i, argv[i]);
// 	}

// 	if(argc != 3){
// 		printf("Please entery path and file name\n");
// 	}



//     return 0;





int main(void) {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char *url = "http://172.16.92.130/O0917/sm32Xtest_V44-8.exe";
    char outfilename[] = "/home/picture/saveimage.exe";
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    return 0;
}
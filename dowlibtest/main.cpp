#include <stdio.h>
#include <curl/curl.h>
//#include <curl/types.h>
#include <curl/easy.h>
#include <string>
#include "include/libDown.h"

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}


int main(void){

    down();
}


// void down(void){
//     CURL *curl;
//     FILE *fp;
//     CURLcode res;
//     char *url = "http://172.16.92.151/hfs/1080p.mov";
//     char outfilename[] = "video.mov";
//     curl = curl_easy_init();
//     const int NUM = 50;
//     if (curl) {
//         fp = fopen(outfilename,"wb");
//         curl_easy_setopt(curl, CURLOPT_URL, url);
//         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
//         curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
//         res = curl_easy_perform(curl);
//         /* always cleanup */
//         curl_easy_cleanup(curl);
//         fclose(fp);
//     }
//     //return 0;
// }

// int main(void) {
//     CURL *curl;
//     FILE *fp;
//     CURLcode res;
//     char *url = "http://172.16.92.151/hfs/1080p.mov";
//     char outfilename[] = "video.mov";
//     curl = curl_easy_init();
//     const int NUM = 50;
//     if (curl) {
//         fp = fopen(outfilename,"wb");
//         curl_easy_setopt(curl, CURLOPT_URL, url);
//         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
//         curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
//         res = curl_easy_perform(curl);
//         /* always cleanup */
//         curl_easy_cleanup(curl);
//         fclose(fp);
//     }
//     return 0;
// }
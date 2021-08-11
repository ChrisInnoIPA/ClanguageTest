#include <stdio.h>
#include <curl/curl.h>
//#include <curl/types.h>
#include <curl/easy.h>
#include <string>



#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main(int argc, char **argv) 
{
    // int i = 0;
    // printf("argc = %d\n", argc);

    // for(i = 0; i = argc; i++){
    //     printf("argv[%d] = %s\n", i, argv[i]);
    // }

    // return 0;





/////////////////////////////////////////////////////////////////

    // int i=0;
    
    // // recover argc and argv
    // argc = 3;
    // argv[0] = "a", argv[1]="b", argv[2]="c";

    // printf("argc = %d\n", argc);
    // for(i=0; i!=argc; ++i) 
    //    printf("argv[%d] = %s\n", i, argv[i]);
    // return 0;

/////////////////////////////////////////////////////////////////

    if (argc!=2)                  //判斷參數輸入是否正確
   {
      cout << "Input error!\n";
      return 1;
   }
   ifstream infile(argv[1]);     //開啟檔案
   if (!infile)                  //判斷是否正確開啟檔案
   {
      cout << "Can not open file!\n";
      return 1;
   }

   char s[]="ABCDEFGHIJKLMNOPQRSTUVWX";
   char t[]="123456789";
   int n,i,m;
   infile >> n;
   for (i=0;i<n;i++) {
      infile >> m;
      cout << s[(m-1)%24] << t[(m-1)%9] << endl ;
   }
   system("pause"); 
   return 0;
}
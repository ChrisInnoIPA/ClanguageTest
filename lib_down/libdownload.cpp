#include <stdio.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <string>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) 
{
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

bool down(char *url, char *path)
{
    CURL 	 *curl;
    FILE 	 *fp;
    CURLcode res;

	printf("url = %s \n", url);
    
    curl = curl_easy_init();

    if (curl) 
    {
        fp = fopen(path,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);		

        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);

		if(res == CURLE_OK)
			return true;
		else
		{
			switch(res)
			{
				case 7:
						printf("Failed to connect() to host or proxy. \n");
						break;
				default:
						break;
			}
		}
    }

	return false;
}

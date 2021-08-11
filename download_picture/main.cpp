#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "libDown.h"

int main(int argc, char **argv)
{
	if(argc >= 2)
		down(argv[1]);
	else
		down("http://172.16.92.151/hfs/1080p.mov");

	return 0;
}
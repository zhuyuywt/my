#include <stdio.h>
#include <stdlib.h>
#include "err_exit.h"


int main(int argc, char *argv[])
{
	int n;
	FILE *from,*to;
	char buf[BUFSIZ];
	if(argc != 3) {
		fprintf(stderr,"Usage: %s from-file to-file\n",*argv);
		exit(1);
	}
	if((from = fopen(argv[1],"r"))==NULL)
		err_exit(argv[1]);
	if((to = fopen(argv[2],"w"))==NULL)
		err_exit(argv[2]);
	while((n = fread(buf,sizeof(char),BUFSIZ,from))>0)
		fwrite(buf,sizeof(char),n,to);
	fclose(from);
	fclose(to);
	exit(0);
}

/*
** pwgen
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* No zero/o, no i/1 no y/z to avoid mistyping/misreading */

const char allowed_chars[] = "abcdefghjklmnpqrstuvwxABCDEFGHJKLMNPQRSTUVWX23456789";

int main(int argc, char *argv[])
{
	int len;
	int i;
	int count;
	char	out[256];

	if(argc==2)
	{
		if((0==strcmp(argv[1],"--help")) || (0==strcmp(argv[1],"-?")))
		{
			fprintf(stderr,"Syntax:\npwgen {maximum-password-length} {count-of-passwords}\n");
			exit(0);
		}
	}
#if defined(__APPLE__) || defined(srandomdev)
	srandomdev();
#else
	srand(time(NULL));
#endif

	if (argc < 2)
	{
		len = 8;
	}
	else
	{
		len = atoi(argv[1]);
	}
	if((len< 1) || (len > 255))
	{
		fprintf(stderr,"%s: indicated length (%d) is not within 1..255\n",argv[0],len);
		goto error;
	}

	if (argc < 3)
	{
		count = 1;
	}
	else
	{
		count = atoi(argv[2]);
	}

	if((count< 1) || (count > 10240))
	{
		fprintf(stderr,"%s: indicated count (%d) is not within 1..1024\n",argv[0],count);
		goto error;
	}

	while(count--)
	{
		for(i=0;i<len;i++)
		{
			out[i] = allowed_chars [ random() % ((sizeof(allowed_chars)-1/sizeof(char))) ];
		}
		out[i] = '\0';
		fprintf(stdout,"%s\n",out);
	}
	return 0;
error:
	return -1;
}

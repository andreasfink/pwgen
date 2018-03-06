/*
** pwgen
*/

#include <stdio.h>
#include <stdlib.h>


/* No zero/o, no i/1 no y/z to avoid mistyping/misreading */

const char allowed_chars[] = "abcdefghjklmnpqrstuvwxABCDEFGHJKLMNPQRSTUVWX23456789";

int main(int argc, char *argv[])
{
	int len;
	int i;
	int count;
	char	out[256];

	srandomdev();
	if (argc < 2)
		len = 8;
	else
		len = atoi(argv[1]);

	if((len< 1) || (len > 255))
	{
		fprintf(stderr,"%s: indicated length (%d) is not within 1..255\n",argv[0],len);
		goto error;
	}

	if (argc < 3)
		count = 1;
	else
		count = atoi(argv[2]);

	if((count< 1) || (count > 10240))
	{
		fprintf(stderr,"%s: indicated count (%d) is not within 1..1024\n",argv[0],count);
		goto error;
	}

	while(count--)
	{
		for(i=0;i<len;i++)
			out[i] = allowed_chars [ random() % ((sizeof(allowed_chars)-1/sizeof(char))) ];
		out[i] = '\0';
		fprintf(stdout,"%s\n",out);
	}
	return 0;
error:
	return -1;
}

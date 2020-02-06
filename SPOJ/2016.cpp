#include <stdio.h>
 
#define BUF_SIZE 1024
 
int main()
{
	size_t i, s, cc[256] = { };
	unsigned char buf[BUF_SIZE];
	do
	{
		s = fread(buf, 1, BUF_SIZE, stdin);
		for(i = 0; i < s; ++i)
			cc[buf[i]]++;
	}
	while(s == BUF_SIZE);
	for(i = 0; i < 256; ++i)
		if(cc[i])
			printf("%d %d\n", i, cc[i]);
	return 0;
}

#include<signal.h>
#define	SIGALRM	14

int main(void)
{
	kill(0, 14);
	return 0;
}

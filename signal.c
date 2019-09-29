#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void sig_handler(int signum);

int main()
{
	alarm(5);
//	signal(SIGALRM, sig_handler);
	signal(SIGALRM, sig_handler);

	for(;;)
		sleep(1);
	
	return(0);
}
void sig_handler(int signum)
{
	printf("Alarm deliverred signum is %d\n", signum);
/*	exit(0); */
	system("/bin/ls");
}

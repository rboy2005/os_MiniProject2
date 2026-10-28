#include "types.h"
#include "stat.h"
#include "user.h"
int main(int argc, char *argv[])
{
	int i;
	int rc;
	printf(1, "Parent PID: %d\n", getpid());
	for (i = 1; i < argc; i++){
		int tickets = atoi(argv[i]);
		rc = fork();
		if (!rc){
			// Child process
			settickets(tickets);
			printf(1,"Child %d PID: %d Tickets: %d\n",i,getpid(),tickets);
			for(;;){}
		}
	}
	exit();
}

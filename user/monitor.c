#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

int main(int argc, char*argv[])
{
    int i;
    int sample;
    struct pstat ps;

    // Print the CSV column names for Excel.
    printf(1, "time,pid,tickets,ticks\n");

    // Collect 30 samples of process scheduling information.
    for (sample = 0; sample < 30; sample++)
    {
	 // Wait 100 system ticks before collecting the next sample.
        sleep(100);

        // Retrieve the current process information from the kernel.
        getpinfo(&ps);

        // Go through every entry in the process table.
        for (i = 0; i < NPROC; i++)
        {
	//Checks whether a process-table slot is occupied - true = printed
            if (ps.inuse[i])
            {
                printf(1, "%d,%d,%d,%d\n",
                       uptime(),
                       ps.pid[i],
                       ps.tickets[i],
                       ps.ticks[i]);
            }
        }
    }
     exit();
}

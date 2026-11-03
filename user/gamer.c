#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int i;
    int pid;
    int start;
    int children = 0;

    for (i = 0; i < 30; i++)
    {
        pid = fork();

        if (pid < 0)
        {
            printf(1, "Error: fork failed\n");
            continue;
        }

        if (pid == 0)
        {
            // records the time when the child begins running for 100 system ticks
            start = uptime();

            while (uptime() - start < 100)
            {
            }

            exit();
        }

        // Parent: count the child and sleep for 20 ticks.
        children++;
        sleep(20);
    }

    // Wait for every child that was successfully created.
    for (i = 0; i < children; i++)
    {
        wait();
    }

    printf(1, "Gamer completed. %d children ran successfully.\n", children);

    exit();
}


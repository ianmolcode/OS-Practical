#include <stdio.h>
#include <conio.h>

void main()
{
    int i, j, n, temp, bt[20], wt[20], tat[20], pos, pr[20];
    float awt = 0, atat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the burst time of the processes: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pr[i]);
    }
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        { // find the process with the highest priority and swap it with the current process
            if (pr[j] < pr[pos])
            {
                pos = j;
            }
        }
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
    }
    wt[0] = 0;
    printf("Process\t\tBurst Time\t\tTurn Around Time\t\tWaiting Time");
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] += bt[j]; // calculate the waiting time
        }
        awt += wt[i];
        tat[i] = wt[i] + bt[i]; // calculate the turn around time
        atat += tat[i];
        printf("\n%d\t\t%d\t\t%d\t\t%d", i + 1, bt[i], tat[i], wt[i]);
    }
    awt = awt / n;
    atat = atat / n;
    printf("\nAverage Waiting Time: %f", awt);
    printf("\nAverage Turn Around Time: %f", atat);
}
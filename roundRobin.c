#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
void main()
{
    int i, j, n, count = 0, bt[20], wt[20], tat[20], qt, temp, sq, rem_bt[10];
    ;
    float awt = 0, atat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the burst time of the processes: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }
    printf("Enter the time quantum: ");
    scanf("%d", &qt);
    while (1)
    {
        for (i = 0, count = 0; i < n; i++)
        {
            temp = qt;
            if (rem_bt[i] == 0) // if the process has finished executing
            {
                count++;
                continue;
            }
            if (rem_bt[i] > qt) // if the process has not finished executing
            {
                rem_bt[i] -= qt;
            }
            else if (rem_bt[i] >= 0) // if the process has finished executing
            {
                temp = rem_bt[i];
                rem_bt[i] = 0;
            }
            sq += temp;
            tat[i] = sq;
        }
        if (n == count)
            break;
    }
    printf("Process\t\tBurst Time\t\tTurn Around Time\t\tWaiting Time");
    for (i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        awt += wt[i];
        atat += tat[i];
        printf("\n%d\t\t%d\t\t%d\t\t%d", i + 1, bt[i], tat[i], wt[i]);
    }
    awt = awt / n;
    atat = atat / n;
    printf("\nAverage Waiting Time: %f", awt);
    printf("\nAverage Turn Around Time: %f", atat);
}
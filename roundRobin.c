#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
void main()
{
    int n, i, qt, count, temp, sq = 0, bt[10], wt[10], tat[10], rem_bt[10];
    float awt = 0, atat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the burst time of the processes: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    while (1)
    {
        for (int i = 0, count = 0; i < n; i++)
        {
            temp = qt; // store the quantum time in temp
            if (rem_bt[i] == 0)
            {
                count++;
                continue; // if the process is completed then continue
            }
            if (rem_bt[i] > qt)
            {
                rem_bt[i] = rem_bt[i] - qt;
            }
            else
            {
                if (rem_bt[i] >= 0)
                {
                    temp = rem_bt[i];
                    rem_bt[i] = 0;
                }
            }
            sq = sq + temp; // store the total time
            tat[i] = sq;    // store the total time in tat
        }
        if (n == count)
        {
            break;
        }
    }
    printf("Process\t\tBurst Time\t\tTurn Around Time\t\tWaiting Time");
    for (i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("\n%d\t\t%d\t\t%d\t\t%d", i + 1, bt[i], tat[i], wt[i]);
    }
    awt = awt / n;
    atat = atat / n;
    printf("\nAverage Waiting Time: %f", awt);
    printf("\nAverage Turn Around Time: %f", atat);
}
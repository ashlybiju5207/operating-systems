#include <stdio.h>
int main()
{
    int n, pid[15], bt[15], at[15], rt[15], wt[15], tat[15], i, j, smallest, count = 0, time;
    float avg_wt = 0, avg_tat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the process IDs: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pid[i]);
    printf("Enter the arrival times: ");
    for (i = 0; i < n; i++)
        scanf("%d", &at[i]);
    printf("Enter the burst times: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }
    rt[15] = 9999;
    for (time = 0; count != n; time++)
    {
        smallest = 15;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0)
            {
                smallest = i;
            }
        }
        rt[smallest]--;
        if (rt[smallest] == 0)
        {
            count++;
            wt[smallest] = time + 1 - at[smallest] - bt[smallest];
            tat[smallest] = time + 1 - at[smallest];
            avg_wt += wt[smallest];
            avg_tat += tat[smallest];
        }
    }
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage waiting time: %f", avg_wt / n);
    printf("\nAverage turnaround time: %f", avg_tat / n);
}

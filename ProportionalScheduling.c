#include <stdio.h>

#define MAX_PROCESSES 10
void proportionalScheduling(int at[], int bt[], int dl[], int n) {
    int completionTimes[MAX_PROCESSES] = {0};
    int tat[MAX_PROCESSES] = {0};
    int wt[MAX_PROCESSES] = {0};
    int time = 0;
    int totalBurstTime = 0;
    int i;

    // Calculate total burst time
    for (i = 0; i < n; i++) {
        totalBurstTime += bt[i];
    }

    // Execute processes proportionally based on burst time
    for (i = 0; i < n; i++) {
        int quantum = (bt[i] * 100) / totalBurstTime;
        time += quantum;
        completionTimes[i] = time;
    }

    // Calculate turnaround and waiting times
    for (i = 0; i < n; i++) {
        tat[i] = completionTimes[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Output the execution order
    printf("\nProportional Scheduling Order:\n");
    for (i = 0; i < n; i++) {
        printf("P%d ", i);
    }
    printf("\n");

    // Output turnaround and waiting times
    printf("\nProcess\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", i, tat[i], wt[i]);
    }
}
int main() {
    int at[MAX_PROCESSES];
    int bt[MAX_PROCESSES];
    int dl[MAX_PROCESSES];
    int n, i;

    printf("Enter the number of processes (max 10): ");
    scanf("%d", &n);

    printf("\nEnter the arrival time, burst time, and deadline for each process:\n");
    for (i = 0; i < n; i++) {
        printf("\nProcess P%d:\n", i);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Deadline: ");
        scanf("%d", &dl[i]);
    }
 proportionalScheduling(at, bt, dl, n);

    return 0;
}
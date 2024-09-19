#include <stdio.h>
void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
wt[0] = 0; // Waiting time for the first process is 0
for (int i = 1; i < n; i++) {
wt[i] = bt[i - 1] + wt[i - 1];
}
}
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {for (int i = 0; i < n; i++) {
tat[i] = bt[i] + wt[i];
}
}

void findAverageTime(int processes[], int n, int bt[]) {
int wt[n], tat[n], total_wt = 0, total_tat = 0;

findWaitingTime(processes, n, bt, wt);

findTurnAroundTime(processes, n, bt, wt, tat);
printf("Processes\t Burst Time\t Waiting Time\t Turnaround Time\n");
for (int i = 0; i < n; i++) {
total_wt += wt[i];
total_tat += tat[i];
printf("|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n", i + 1, bt[i], wt[i], tat[i]);
}

printf("Average Waiting Time = %.2f\n", (float)total_wt / n);
printf("Average Turnaround Time = %.2f\n", (float)total_tat / n);
}

int main() {
int n;


printf("Enter number of processes: ");
scanf("%d", &n);

int processes[n], burst_time[n];


for (int i = 0; i < n; i++) {
processes[i] = i + 1;
printf("Enter burst time for process %d: ", i + 1);
scanf("%d", &burst_time[i]);
}
printf("\nFCFS scheduling algorithm\n");
printf("\n");

findAverageTime(processes, n, burst_time);

return 0;
}



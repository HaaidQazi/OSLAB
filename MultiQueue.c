#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;
    int arrivalTime;
    int burstTime;
} Process;

void fcfsScheduling(Process queue[], int numProcesses) {
    int i;
    int currentTime = 0;

    for (i = 0; i < numProcesses; i++) {
        if (queue[i].arrivalTime > currentTime) {
            currentTime = queue[i].arrivalTime;
        }

        printf("Running process P%d at time %d\n", queue[i].pid, currentTime);
        currentTime += queue[i].burstTime;
    }
}

int main() {
    Process systemQueue[MAX_PROCESSES];
    Process userQueue[MAX_PROCESSES];
    int numSystemProcesses = 0;
    int numUserProcesses = 0;
    int i, numProcesses;

    printf("Enter the number of system processes: ");
    scanf("%d", &numProcesses);

    printf("Enter the arrival time and burst time for each system process:\n");
    for (i = 0; i < numProcesses; i++) {
        printf("Process P%d:\n", i+1);
        systemQueue[numSystemProcesses].pid = i+1;
        printf("Arrival Time: ");
        scanf("%d", &systemQueue[numSystemProcesses].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &systemQueue[numSystemProcesses].burstTime);
        numSystemProcesses++;
    }

    printf("\nEnter the number of user processes: ");
    scanf("%d", &numProcesses);

    printf("Enter the arrival time and burst time for each user process:\n");
    for (i = 0; i < numProcesses; i++) {
        printf("Process P%d:\n", i+1);
        userQueue[numUserProcesses].pid = i+1;
        printf("Arrival Time: ");
        scanf("%d", &userQueue[numUserProcesses].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &userQueue[numUserProcesses].burstTime);
        numUserProcesses++;
    }

    // Print the processes in the system queue
    printf("\nSystem processes:\n");
    for (i = 0; i < numSystemProcesses; i++) {
        printf("P%d\tArrival Time: %d\tBurst Time: %d\n", systemQueue[i].pid, systemQueue[i].arrivalTime, systemQueue[i].burstTime);
    }

    // Print the processes in the user queue
    printf("\nUser processes:\n");
    for (i = 0; i < numUserProcesses; i++) {
        printf("P%d\tArrival Time: %d\tBurst Time: %d\n", userQueue[i].pid, userQueue[i].arrivalTime, userQueue[i].burstTime);
    }

    // Run FCFS scheduling for the system queue
    printf("\nRunning FCFS scheduling for system processes:\n");
    fcfsScheduling(systemQueue, numSystemProcesses);

    // Run FCFS scheduling for the user queue
    printf("\nRunning FCFS scheduling for user processes:\n");
    fcfsScheduling(userQueue, numUserProcesses);

    return 0;
}

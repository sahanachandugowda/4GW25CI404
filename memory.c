#include <stdio.h>
int main() {
int m, n, i, j, choice;
int blockSize[10], tempBlock[10];
int processSize[10], allocation[10];
int internalFragmentation = 0;
// Input number of memory blocks
printf("Enter number of memory blocks: ");
scanf("%d", &m);
// Input size of each block
printf("Enter size of each block:");
for (i = 0; i < m; i++) {
scanf("%d", &blockSize[i]);
}
// Input number of processes
printf("Enter number of processes: ");
scanf("%d", &n);
// Input size of each process
printf("Enter size of each process:");
for (i = 0; i < n; i++) {
scanf("%d", &processSize[i]);
}
// Copy original block sizes
for (i = 0; i < m; i++)
tempBlock[i] = blockSize[i];
// Initialize allocation array
for(i = 0; i < n; i++)
   allocation[i] = -1;
// Menu
printf("Choose Memory Allocation Method:");
printf("1. First Fit 2. Best Fit 3. Worst Fit");
printf("Enter your choice: ");
scanf("%d", &choice);
// Allocation logic
for (i = 0; i < n; i++) {
int selected = -1;
for (j = 0; j < m; j++) {
if (tempBlock[j] >= processSize[i]) {
if (choice == 1) { // First Fit
selected = j;
break;
}
if (choice == 2) { // Best Fit
if (selected == -1 || tempBlock[j] < tempBlock[selected])
selected = j;
}
if (choice == 3) { // Worst Fit
if (selected == -1 || tempBlock[j] > tempBlock[selected])
selected = j;
}
}
}
if (selected != -1) {
allocation[i] = selected;
tempBlock[selected] -= processSize[i];
}
}
// Display allocation details
printf("Process No Process Size Block No Fragmentation");
for (i = 0; i < n; i++) {
printf("%d %d ", i + 1, processSize[i]);
if (allocation[i] != -1) {
int frag = tempBlock[allocation[i]];
internalFragmentation += frag;
printf("%d %d", allocation[i] + 1, frag);
} else {
printf("Not Allocated --");
}
}
printf("Total Internal Fragmentation = %d", internalFragmentation);
return 0;
}

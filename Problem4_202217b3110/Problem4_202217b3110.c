#include <stdio.h>

void moveDisks(int num_disks, char source_rod, char target_rod, char auxiliary_rod) {
    if (num_disks == 1) {
        printf("\nMove disk 1 from rod %c to rod %c", source_rod, target_rod);
        return;
    }
    moveDisks(num_disks - 1, source_rod, auxiliary_rod, target_rod);
    printf("\nMove disk %d from rod %c to rod %c", num_disks, source_rod, target_rod);
    moveDisks(num_disks - 1, auxiliary_rod, target_rod, source_rod);
}

int main() {
    int num_disks = 4; // Number of disks
    moveDisks(num_disks, 'A', 'C', 'B'); // A is the source rod, C is the target rod, B is the auxiliary rod
    return 0;
}

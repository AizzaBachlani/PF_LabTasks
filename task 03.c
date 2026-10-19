#include <stdio.h>
int isValidMark(int m) {
    if (m >= 0 && m <= 100) {
        return 1;
    }
	else {
        return 0;
    }
}
void findMinMax(int arr[], int size, int *min, int *max) {
    int i;
    *min = arr[0];
    *max = arr[0];
    for (i = 1; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}
int main() {
    int marks[5];
    int i, min, max;
    for (i = 0; i < 5; i++) {
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks[i]);
        while (isValidMark(marks[i]) == 0) {
            printf("Invalid mark, enter again: ");
            scanf("%d", &marks[i]);
        }
    }
    findMinMax(marks, 5, &min, &max);
    printf("\nLowest mark = %d\n", min);
    printf("Highest mark = %d\n", max);
    return 0;
}

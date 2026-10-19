#include <stdio.h>
int square(int x) {
    return x * x;
}
int negate(int x) {
    return -x;
}
int isEven(int x) {
    return x % 2 == 0;
}
int isPositive(int x) {
    return x > 0;
}
void applyToArray(int *arr, int n, int (*fn)(int)) {
    int i;
    for (i = 0; i < n; i++) {
        *(arr + i) = fn(*(arr + i));
    }
}
int countIf(const int *arr, int n, int (*pred)(int)) {
    int i, count = 0;
    for (i = 0; i < n; i++) {
        if (pred(*(arr + i))) {
            count++;
        }
    }
    return count;
}
void printGeneric(void *data, char type, int n) {
    int i;
    if (type == 'i') {
        int *ptr = (int *)data;
        for (i = 0; i < n; i++) {
            printf("%d ", *(ptr + i));
        }
    } else if (type == 'f') {
        float *ptr = (float *)data;
        for (i = 0; i < n; i++) {
            printf("%.2f ", *(ptr + i));
        }
    } else if (type == 'c') {
        char *ptr = (char *)data;
        for (i = 0; i < n; i++) {
            printf("%c ", *(ptr + i));
        }
    } else {
        printf("Invalid type '%c' for printGeneric\n", type);
        return;
    }
    printf("\n");
}
int main() {
    int arr[] = {3, -2, 8, -5, 6};
    float floats[] = {1.5, 2.5, 3.5};
    char chars[] = {'A', 'B', 'C'};
    int n, i;
    do {
        printf("Enter n (1-50): ");
        scanf("%d", &n);
        if (n < 1 || n > 50) {
            printf("Invalid size\n");
        }
    } while (n < 1 || n > 50);
    if (n > 5) {
        printf("The given array contains only 5 elements. Using n = 5.\n");
        n = 5;
}
    printf("\nOriginal array: ");
    printGeneric(arr, 'i', n);
    printf("Number of even elements: %d\n", countIf(arr, n, isEven));
    printf("Number of positive elements: %d\n", countIf(arr, n, isPositive));
    applyToArray(arr, n, square);
    printf("After squaring: ");
    printGeneric(arr, 'i', n);
    applyToArray(arr, n, negate);
    printf("After negating: ");
    printGeneric(arr, 'i', n);
    printf("\nFloat array: ");
    printGeneric(floats, 'f', 3);
    printf("Character array: ");
    printGeneric(chars, 'c', 3);
    printf("Testing invalid type:\n");
    printGeneric(arr, 'x', n);
    return 0;
}

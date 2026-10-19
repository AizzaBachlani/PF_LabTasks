#include <stdio.h>
int add(int a, int b, int *result) {
    *result = a + b;
    return 1;
}
int subtract(int a, int b, int *result) {
    *result = a - b;
    return 1;
}
int multiply(int a, int b, int *result) {
    *result = a * b;
    return 1;
}
int divide(int a, int b, int *result) {
    if (b == 0) {
        return 0;
    }
    *result = a / b;
    return 1;
}
int main() {
    int (*ops[])(int, int, int *) = {
        add, subtract, multiply, divide
    };
    char *names[] = {
        "Add", "Subtract", "Multiply", "Divide"
    };
    int choice, a, b, result, success;
    do {
        printf("\n--- Simple Calculator ---\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 5) {
            printf("Invalid choice\n");
            continue;
        }
        if (choice == 5) {
            printf("Exiting calculator.\n");
            break;
        }
        printf("Enter two integers: ");
        scanf("%d %d", &a, &b);
        success = ops[choice - 1](a, b, &result);
        if (success == 1) {
            printf("%s result = %d\n",
                   names[choice - 1], result);
        } else {
            printf("Error: Division by zero is not allowed.\n");
        }
    } while (choice != 5);
    return 0;
}

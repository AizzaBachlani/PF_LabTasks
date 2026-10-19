#include <stdio.h>
int deposit(float *balance, float amount) {
    if (amount <= 0) {
        return 0;
    }
    *balance = *balance + amount;
    return 1;
}
int withdraw(float *balance, float amount) {
    if (amount <= 0 || amount > *balance) {
        return 0;
    }
    *balance = *balance - amount;
    return 1;
}
int main() {
    float balance = 1000.0, amount;
    int choice;
    do {
        printf("\n--- Bank Account Menu ---\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                if (deposit(&balance, amount)) {
                    printf("Deposit successful.\n");
                } else {
                    printf("Invalid amount.\n");
                }
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (withdraw(&balance, amount)) {
                    printf("Withdrawal successful.\n");
                } else {
                    printf("Invalid amount or insufficient balance.\n");
                }
                break;
            case 3:
                printf("Current balance: %.2f\n", balance);
                break;
            case 4:
                printf("Thank you for using the banking system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}

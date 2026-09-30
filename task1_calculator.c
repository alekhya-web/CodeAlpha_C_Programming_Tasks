#include <stdio.h>

int main() {
    char operator;
    double num1, num2, result;
    char choice;

    do {
        printf("\n=================================\n");
        printf("    Simple Arithmetic Calculator\n");
        printf("=================================\n");

        printf("Enter first number: ");
        if (scanf("%lf", &num1) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Enter an operator (+, -, *, /): ");
        scanf(" %c", &operator);

        printf("Enter second number: ");
        if (scanf("%lf", &num2) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (operator) {
            case '+':
                result = num1 + num2;
                printf("\nResult: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case '-':
                result = num1 - num2;
                printf("\nResult: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case '*':
                result = num1 * num2;
                printf("\nResult: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;

            case '/':
                if (num2 == 0) {
                    printf("\nError: Division by zero is not allowed.\n");
                } else {
                    result = num1 / num2;
                    printf("\nResult: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;

            default:
                printf("\nError: Invalid operator '%c'. Please use +, -, *, or /.\n", operator);
                break;
        }

        printf("\nDo you want to perform another calculation? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using the calculator. Goodbye!\n");
    return 0;
}

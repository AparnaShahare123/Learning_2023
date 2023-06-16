#include <stdio.h>

int main() {
    float operand1, operand2, result;
    char operator;
    printf("Enter Number1: ");
    scanf("%f", &operand1);

    printf("Enter the operator: ");
    scanf(" %c", &operator);

    printf("Enter Number2: ");
    scanf("%f", &operand2);
    switch (operator) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            // Check for division by zero
            if (operand2 != 0) {
                result = operand1 / operand2;
            } else {
                printf("Error: Division by zero is not allowed.\n");
                return 1;  // Exit the program with an error code
            }
            break;
        default:
            printf("Error: Invalid operator.\n");
            return 1;  // Exit the program with an error code
    }

    // Printing the result
    printf("Result: %.2f\n", result);

    return 0;
}

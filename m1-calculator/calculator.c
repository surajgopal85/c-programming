#include <stdio.h>

int main() {
    int oper;
    int num1;
    int num2;

    printf("Welcome. choose an integer operation by entering the number associated:\n1. addition\n2. subtraction\n3. multiplication\n4. division\n5. remainder of division");
    scanf("%d", &oper);
    printf("Enter first number for operation");
    scanf("%d", &num1);
    printf("Enter second number for operation");
    scanf("%d", &num2);

    if (oper == 1) {
        printf("%d + %d = %d", num1, num2, num1 + num2);
    } else if (oper == 2) {
        printf("%d - %d = %d", num1, num2, num1 - num2);
    } else if (oper == 3) {
        printf("%d * %d = %d", num1, num2, num1 * num2);
    } else if (oper == 4) {
        printf("%d / %d = %d", num1, num2, num1 / num2);
    } else if (oper == 5) {
        printf("%d %% %d - %d", num1, num2, num1 % num2);
    } else {
        printf("You've chosen an invalid choice, goodbye!");
    }
    return 0;
}
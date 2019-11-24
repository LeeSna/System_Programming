#include <stdio.h>
#include "cal.h"

void main() {

    double a, b;
    double result_add, result_subtract;
    double result_multiply, result_divide;

    printf("사칙 연산\n");
    printf("첫번째 숫자 입력 : ");
    scanf("%lf", &a);
    printf("두번째 숫자 입력 : ");
    scanf("%lf", &b);

    result_add = add(a, b);
    result_subtract = subtract(a, b);
    result_multiply = multiply(a, b);
    result_divide = divide(a, b);

    printf("add : %.2lf\n", result_add);
    printf("subtract : %.2lf\n", result_subtract);
    printf("multiply : %.2lf\n", result_multiply);
    printf("divide : %.2lf\n", result_divide);
    
}

#include <stdio.h>

int Factorial(int n) {
    int temp = 1;
    for (int i = 0; i <= n; i++) {
        temp *= i;
    }
    return temp;
}
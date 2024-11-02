#include <stdio.h>

int Factorial(int n) {
    if (n < 2) {
        return 1;
    } else {
        return Factorial(n-1);
    }
}
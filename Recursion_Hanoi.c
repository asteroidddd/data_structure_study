#include <stdio.h>

int Hanoi(n) {
    if (n == 1) {
        return 1;
    } else {
        return 2 * Hanoi(n-1) + 1;
    }
}
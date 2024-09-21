#include <stdio.h>

int Hanoi(n) {
    if (n == 1) {
        return 1;
    }
    int past, now;
    past = 1;
    for (int i = 2; i <= n; i++) {
        now = 2 * past + 1;
        past = now;
    }
    return now;
}
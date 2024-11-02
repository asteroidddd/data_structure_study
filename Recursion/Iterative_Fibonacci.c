#include <stdio.h>

int Fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    int pastpast = 0, past = 1, now;
    for (int i = 2; i <= n; i++) {
        now = pastpast + past;
        pastpast = past;
        past = now;
    }
    return now;
}
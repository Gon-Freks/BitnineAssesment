
#include <stdio.h>
#include <stdlib.h>

// Simple recursive solution
int recurrence1(int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    return recurrence1(n - 3) + recurrence1(n - 2);
}

// Dynamic programming solution with linear space
int recurrence2(int n) {
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; ++i)
        dp[i] = dp[i - 3] + dp[i - 2];
    return dp[n];
}


// Iterative solution with constant space
int recurrence3(int n) {
    int a = 0, b = 1, c = 2;
    int d;
    if(n == 0)
        return a;
    if(n == 1)
        return b;
    if(n == 2)
        return c;
    for(int i = 3; i <= n; ++i) {
        d = a + b;
        a = b;
        b = c;
        c = d;
    }
    return d;
}


int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("The output from the first recurrence1 %d\n", recurrence1(n));
    printf("The output from the first recurrence2 %d\n", recurrence2(n));
    printf("The output from the first recurrence3 %d\n", recurrence3(n));
    return 0;
}


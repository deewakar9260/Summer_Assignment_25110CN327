#include <stdio.h>
double power_efficient(double x, int n) {
    double result = 1.0;
    long long abs_n = n; 
    if (abs_n < 0) {
        abs_n = -abs_n;
        x = 1.0 / x;
    }
    while (abs_n > 0) {
        if (abs_n & 1) {
            result *= x;
        }
        x *= x;     
        abs_n >>= 1;   
    }
    return result;
}
int main() {
    double x;
    int n;
    printf("Enter base (x): ");
    scanf("%lf", &x);
    printf("Enter exponent (n): ");
    scanf("%d", &n);
    double res = power_efficient(x, n);
    printf("%.4f raised to the power %d is: %.4f\n", x, n, res);
    return 0;
}

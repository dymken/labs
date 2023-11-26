#include <stdio.h>
#include <math.h>

double factorial(int n) 
{
    double result = 1;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

float sin3e(float x, double e)
{
    double sum = 0;
    double sign = 1;
    double m = 0;
    int i = 1;
    do {
        m = (sign * (pow(9, i) - 1) * pow(x, 2 * i + 1)) / factorial(2 * i + 1);
        sum += m;
        sign = -sign;
        i++;
    } while (fabs(m) > e);
    return sum * 3 / 4;
}

float sin3n(float x, int n)
{
    double sum = 0;
    double sign = 1;
    double m = 0;
    for (int i = 1; i <= n; i++)
    {
        m = (sign * (pow(9, i) - 1) * pow(x, 2 * i + 1)) / factorial(2 * i + 1);
        sum += m;
        sign = -sign;
    }
    return sum * 3 / 4;
}

int main(void)                      
{                                   
    printf("Value = %f and %f", sin3e(0.5, 1e-6), sin3n(0.5, 10));
    return 0;                       
}
#include <bits/stdc++.h>
using namespace std;

double eps = 1e-6;

double f(double x)
{
    return x * x * x - 5 * x * x + 10 * x - 80;
    //return pow(x, 3) - 5 * pow(x, 2) + 10 * x - 80;
}
int main()
{
    double root, x1 = 0, x2 = 100, y;
    root = x1 + (x2 - x1) / 2;
    // int time=1;
    y = f(root);
    while (fabs(y) > eps)
    {
        if (y > 0)
            x2 = root;
        else
            x1 = root;
        root = x1 + (x2 - x1) / 2;
        y = f(root);
        // time++;
    }
    printf("%.8f\n", root);
    // printf("%d",time);
    return 0;
}
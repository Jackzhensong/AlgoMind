#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n <= 3) {
        cout << "NO\n";
        return 0;
    }

    else {
        cout << "YES\n";
        if (n % 2 == 0) {
            printf("1 * 2 = 2\n");
            printf("2 * 3 = 6\n");
            printf("6 * 4 = 24\n");
            for (int i = n; i >= 6; i -= 2) {
                printf("%d - %d = 1\n", i, i-1);
                printf("24 * 1 = 24\n");
            }
        }
        else {
            printf("5 - 2 = 3\n");
            printf("3 - 1 = 2\n");
            printf("3 * 2 = 6\n");
            printf("6 * 4 = 24\n");
            for (int i = n; i >= 7; i -= 2) {
                printf("%d - %d = 1\n", i, i-1);
                printf("24 * 1 = 24\n"); 
            }
        }
    }
    return 0;
}
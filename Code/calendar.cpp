#include<iostream>
#include<vector>
using namespace std;

bool isleap(int year) {
    if((year % 4 ==0 && year % 100 != 0) || year % 400 == 0) 
        return true;
    return false;
}

char week[7][10] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
int year[2] = { 365, 366 };
int month[2][12] = { 31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31 };

int main() {
    int days, weeks;
    int i, j;

    while(cin >> days && days != -1) {
        weeks = days % 7;

        for(i = 2000; days >= year[isleap(i)]; ++i) 
            days -= year[isleap(i)];

        for(j = 0; days >= month[isleap(i)][j]; ++j)
            days -= month[isleap(i)][j];

        printf("%d-%02d-%02d %s\n", i, j+1, days+1, week[weeks]);
    }
}
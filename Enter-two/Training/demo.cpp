#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 10010;
int school[maxn] = {0};

int main() {
    int n, schID, score;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d%d", &schID, &score);
        school[schID] += score;
    }
    
    int k = 1, maxscore = -1;
    for(int i = 0; i < n; ++i) {
        if(school[i] > maxscore) {
            maxscore = school[i];
            k = i;
        }
    }
    printf("%d %d", k, maxscore);
    return 0;
}



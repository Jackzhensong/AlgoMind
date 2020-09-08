#include <cstdio>
#include <algorithm>
using namespace std;

struct moon {
    double store;
    double sell;
    double price;
}cake[1010];

bool cmp(moon a, moon b) {
    return a.price > b.price;
}

int main() {
    int n; 
    double d;
    scanf("%d%lf", &n, &d);
    for(int i = 0; i < n; ++ i) 
        scanf("%lf", &cake[i].store);

    for(int i = 0; i < n; ++ i) {
        scanf("%lf", &cake[i].sell);
        cake[i].price = cake[i].sell / cake[i].store;
    }

    sort(cake, cake + n, cmp);
    double ans = 0;
    for(int i = 0; i < n; ++ i) {
        if(cake[i].store <= d) {
            d -= cake[i].store;
            ans += cake[i].sell;
        }
        else {
            ans += cake[i].price * d;
            break;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}



int main() {
    int count[10];
    for(int i = 0; i < 10; ++ i) {
        scanf("%d", &count[i]);
    }

    for(int i = 0; i < 10; ++ i) {
        if(count[i] != 0) {
            printf("%d", i);
            count[i] --;
            break;
        }
    }
    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < count[i]; ++ j) 
            printf("%d", i);
    return 0;
}



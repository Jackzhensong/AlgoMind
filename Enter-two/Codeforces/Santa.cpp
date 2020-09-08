#include<iostream>      // 圣诞老人送礼物
#include<cstdio>
#include<algorithm>
using namespace std;
const double eps = 1e-6;

struct Candy{
    int v, w;
    bool operator <(const Candy & c){
        return double(v)/w - double(c.v) / c.w <eps;
    }
}candies[110];

int main()
{
    int n, w;
    cin>>n>>w;
    for(int i=0; i< n; ++i){
        cin>>candies[i].v>>candies[i].w;
    }
    sort(candies, candies + n);
    int totalW = 0;
    double totalV =0;

    for (int i = 0; i < n; ++i)
    {
        if (totalW + candies[i].w <= w)
        {
            totalW += candies[i].w;
            totalV += candies[i].v;
        }
        else
        {
            totalV += double(candies[i].v / candies[i].w) * (w - totalW) ;
            break;
        }
    }
    printf("%.1f", totalV);
    return 0;
}
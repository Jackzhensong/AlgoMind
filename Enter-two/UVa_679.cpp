#include <bits/stdc++.h>
using namespace std;
const int maxd = 20;

//int s[1 << maxd];   //最大结点个数为2^maxd-1

int main()
{
    int D, I;

    /*while (scanf("%d%d", &D, &I) == 2)
    {
        memset(s, 0, sizeof(s));        //开关
        int k, n = (1 << D) - 1;        //n是最大结点编号
        for (int i = 0; i < I; i++){    //连续让I个小球下落
            k = 1;
            for (;;){
                s[k] = !s[k];
                k = s[k] ? k * 2 : k * 2 + 1;   //根据开关状态选择下落方向
                if (k > n)  break;          //已经落“出界”了
            }
        }
        printf("%d\n", k / 2); //“出界”之前的叶子编号
    } */

    while (scanf("%d%d", &D, &I) == 2)   //直接模拟最后一个小球的路线
    {
        int k = 1;
        for (int i = 1; i<= D - 1; i++)
            if (I % 2){
                k = k * 2;
                I = (I + 1) / 2;
            }
            else{
                k = k * 2 + 1;
                I /= 2;
            }
        printf("%d\n", k);
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int h,m;
    scanf("%d:%d",&h,&m);
    int k=(h%10)*10+h/10;
    int f=(h%10+1)*10+h/10;
    if(h<6||h>=20||(h>=10&&h<=15))
    {
    if(m<=k) cout<<k-m;
    else {
        if(h==15) cout<<(20-h-1)*60+(60-m)+2;
        else if(h==23) cout<<60-m;
        else cout<<(60-m+f);
        }
    }
    else if(h>=6&&h<=9){
        cout<<(10-h-1)*60+(60-m)+1;
    }
    else if(h>=16&&h<=19){
        cout<<(20-h-1)*60+(60-m)+2;
    }
    return 0;
}
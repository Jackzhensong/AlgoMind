#include<bits/stdc++.h>
using namespace std;

int main()
{
    char a[300];
    cin.getline(a,sizeof(a));
    int L=strlen(a);
    int k=0;
    for(int i=0;i<L;i++){
        if(a[i]>='0' && a[i]<='9')
            k++;
    }
    cout<<k;
    return 0;
}
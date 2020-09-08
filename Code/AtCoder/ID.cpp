#include<bits/stdc++.h>
using namespace std;

//const int maxn=100010;

int a[maxn], b[maxn], c[maxn];
struct ID{
    int p;
    int year;
};

struct rule{
    bool operator () (const ID &y1, const ID &y2){
        return y1.year < y2.year;
    }
}

int main()
{
    int N,M;
    cin>>N>>M;
    set<int,int> st;
    multimap<int,int> mp;
    for(int i=0;i<M;i++){
        cin>>ID.p>>ID.year;
        mp.insert(make_pair(ID.p, ID.year));
    }
    
    for(int i=0;i<M;i++){
        printf("%06d%06d\n", a[i], b[i]);
    }
    return 0;
}

int main(){

    int N,M;
    scanf("%d %d",&N,&M);
    int P[M],Y[M],Index[M],Count[N+1]={0};
    for(int i=0;i<M;i++){
        scanf("%d %d",P+i,Y+i);
        Index[i] = i;
    }
 
    sort(Index,Index+M,[&](int a, int b){return Y[a]<Y[b];});

    for(int i=0;i<M;i++){
        Y[Index[i]] = ++Count[P[Index[i]]];
    }
    for(int i=0;i<M;i++){
        printf("%06d%06d\n",P[i],Y[i]);
    }
}

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct Cow{
    int beginmilk, endmilk;
    int No;
    bool operator <(const Cow & c) const {
        return beginmilk < c.beginmilk;
    }
}cow[50010];

int pos[50010];
struct Stall{
    int end;
    int No;
    bool operator < (const Stall & s) const{
        return end > s.end;
    }
    Stall(int e, int n):end(e),No(n) { }
};

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>cow[i].beginmilk>>cow[i].endmilk;
        cow[i].No = i;
    }
    sort(cow, cow + n);
    int total = 0;
    priority_queue<Stall> pq;
    for(int i=0; i<n; ++i){
        if(pq.empty()) {
            ++total;
            pq.push(Stall(cow[i].beginmilk, total));
            pos[cow[i].No] = total;
        }
        else {
            Stall st = pq.top();
            if(st.end < cow[i].beginmilk){
                pq.pop();
                pos[cow[i].No] = st.No;
                pq.push(Stall(cow[i].endmilk, st.No));
            }
            else {
                ++total;
                pq.push(Stall(cow[i].endmilk, total));
                pos[cow[i].No] = total;
            }
        }
    }
    cout<<total<<endl;
    for(int i=0; i<n; ++i){
        cout<<pos[i]<<endl;
    }
    return 0;
}

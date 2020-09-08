#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
const int maxn = 100 + 10;
int main(){
    int n;
    cin>>n;
    set<int> st;
    int a[maxn];
    for(int i = 0; i < n; ++i)
        cin>>a[i];
    for(int i = 0; i < n; ++i)
        st.insert(a[i]);
    set<int>::iterator p;
    cout<<st.size()<<endl;
    for(p = st.begin(); p != st.end(); ++p)
        cout<< *p<<" ";
    return 0;
}
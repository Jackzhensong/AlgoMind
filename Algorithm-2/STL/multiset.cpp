#include<bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int> st;
    int a[]={1,14,12,13,7,13,21,19,8,8};
    for(int i=0;i<10;i++)
        st.insert(a[i]);
    multiset<int>::iterator i;
    for(i=st.begin();i!=st.end();i++)
        cout<<*i<<",";
    cout<<endl;
    cout<<*st.begin();
    i=st.find(22);
    if(i==st.end())
        cout<<"not found"<<endl;
    st.insert(22);
    i=st.find(22);
    if(i==st.end())
        cout<<"not found"<<endl;
    else 
        cout<<"found:"<<*i<<endl;
    i=st.lower_bound(9);
    cout<<*i<<endl;
    i=st.upper_bound(14);
    cout<<*i<<endl;
    st.erase(i);
    for(i=st.begin();i!=st.end();i++)
        cout<<*i<<",";
    return 0;
}
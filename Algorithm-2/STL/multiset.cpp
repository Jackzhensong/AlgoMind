#include <bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int> st;
    int a[] = {1, 14, 12, 13, 7, 13, 21, 19, 8, 8};

    for (int i = 0; i < 10; i++) st.insert(a[i]);

    multiset<int>::iterator i;
    for (i = st.begin(); i != st.end(); i++) cout << *i << ",";

    cout << endl << *st.begin() << endl;

    i = st.find(22);
    if (i == st.end()) cout << "not found" << endl;

    st.insert(22);
    i = st.find(22);
    if (i == st.end()) cout << "not found" << endl;
    else cout << "found:" << *i << endl;

    i = st.lower_bound(13);  // 查找一个最大位置i，使[begin, i)中所有元素都比 val 小
    cout << *i << endl;

    i = st.upper_bound(9); // 查找一个最小位置i, 使得[i, end)中所有元素都比 val 大
    cout << *i << endl;

    st.erase(i);
    for (i = st.begin(); i != st.end(); i++) cout << *i << ",";
    return 0;
}
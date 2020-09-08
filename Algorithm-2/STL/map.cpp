#include <bits/stdc++.h>
using namespace std;

struct word
{
    int times;
    string wd;
};

struct rule
{
    bool operator()(const word &w1, const word &w2)
    {
        if (w1.times != w2.times)
            return w1.times > w2.times;
        else
            return w1.wd < w2.wd;
    }
};

int main()
{
    string s;
    set<word, rule> st;
    map<string, int> mp;
    while (cin >> s)
        ++mp[s];
    for (map<string, int>::iterator i = mp.begin(); i != mp.end(); ++i)
    {
        word tmp;
        tmp.wd = i->first;
        tmp.times = i->second;
        st.insert(tmp);
    }
    for (set<word, rule>::iterator i = st.begin(); i != st.end(); i++)
        cout << i->wd << " " << i->times << endl;
    return 0;
}
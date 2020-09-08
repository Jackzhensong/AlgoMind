#include<bits/stdc++.h>
using namespace std;

int main() {
    set<int, greater<int> > s;
    for(int i = 1; i <= 10; ++i)
        s.insert(i);
    set<int, greater<int> >::iterator it;
    for(it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
    return 0;
}
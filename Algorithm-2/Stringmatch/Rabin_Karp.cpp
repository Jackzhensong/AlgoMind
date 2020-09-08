
#include <bits/stdc++.h>
using namespace std;

int RK(string s, string p) {
    unordered_set<string> Hash;
    m.insert(p);

    for(int i = 0; i <= s.length() - p.length(); ++i) {
        if(Hash.find(s.substr(i, p.length())) == Hash.end()) 
            ++i;
        else return i;
    }
    return -1;
}
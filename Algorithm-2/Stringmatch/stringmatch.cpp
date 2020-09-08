
#include <bits/stdc++.h>
using namespace std;

//
int FindPat_1(string s, string p, int startindex)
{
    int lastindex = s.length() - p.length();
    int count = p.length();
    if (lastindex < startindex)
        return -1;

    for (int g = startindex; g <= lastindex; ++g)
    {
        if (p == s.substr(g, count))
            return g;
    }
    return -1;
}

//
int FindPat_2(string t, string p, int startindex)
{
    int lastindex = t.length() - p.length();
    if (lastindex < startindex)
        return -1;

    int i = startindex, j = 0;
    while (i < t.length() && j < p.length())
        if (p[j] == t[i])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    if (j >= p.length())
        return i - j;
    else
        return -1;
}

//
int FindPat_3(string t, string p, int startindex)
{
    for (int g = startindex; g <= t.length() - p.length(); ++g)
    {
        for (int j = 0; ((j < p.length()) && (t[g + j] == p[j])); ++j)
            if (j == p.length())
                return g;
    }
    return -1;
}

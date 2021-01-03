
#include <bits/stdc++.h>
using namespace std;

int kmpstrmat(string s, string p, int *next, int start)
{
    int i = start, j = 0;
    int slen = s.length();
    int plen = p.length();

    if (slen - start < plen)
        return -1;

    while (i < slen && j < plen) 
    {
        if (j == -1 || s[i] == p[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if (j >= plen)
        return i - plen;
    else
        return -1;
}

//
int Findnext(string p)
{
    int j, k;
    int m = p.length();
    int *next = new int[m];
    next[0] = -1;
    j = 0;
    k = -1;
    while (j < m - 1)
    {
        while (k >= 0 && p[k] != p[j]) k = next[k];
        j++;
        k++;
        next[j] = k;
    }
    return next;
}

//
int Findnext(string p)
{
    int j, k;
    int m = p.length();
    int *next = new int[m];
    next[0] = -1;
    j = 0;
    k = -1;
    while (j < m - 1)
    {
        while (k >= 0 && p[k] != p[j]) k = next[k];
        j++;
        k++;
        if (p[k] == p[j])
            next[j] = next[k];
        else
            next[j] = k;
    }
    return next;
}

//
void getnext(char *p, int *next)
{
    next[0] = -1;
    int i = 0, j = -1;
    while (i < strlen(p))
    {
        if (j == -1 || p[i] == p[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
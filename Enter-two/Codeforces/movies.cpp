#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Rule
{
    int begin, end;
    bool operator<(const Rule &m) const
    {
        return end < m.end;
    }
} movies[100];

int main()
{
    int n, begin, end, count = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> movies[i].begin >> movies[i].end;
    }
    int zero;
    cin >> zero;
    sort(movies, movies + n);
    end = movies[0].end;
    for (int i = 1; i < n; ++i)
    {
        if (movies[i].begin >= end)
        {
            count++;
            end = movies[i].end;
        }
    }
    cout << count + 1 << endl;
    return 0;
}
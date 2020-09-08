#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int lef, chance;
char s[maxn], s2[maxn];
int win, lose;
void guess(char ch)
{
    int bad = 1;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ch)
        {
            lef--;
            s[i] = ' ';
            bad = 0;
        }
        if (bad)
            --chance;
        if (!chance)
            lose = 1;
        if (!lef)
            win = 1;
    }
}
int main()
{
    int rnd;
    while (scanf("%d", &rnd) == 1 && rnd != -1)
    {
        cin>>s>>s2;
        cout << "Round " << rnd << endl;
        win = lose = 0;
        lef = strlen(s);
        chance = 7;
        for (int i = 0; i < strlen(s2); i++)
        {
            guess(s2[i]);
            if (win || lose)
                break;
        }
        if (win)
            cout << "You win." << endl;
        else if (lose)
            cout << "You lose." << endl;
        else
            cout << "You chickened out." << endl;
    }
    return 0;
}
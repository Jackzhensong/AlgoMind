#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, P;
    cin >> N >> M >> P;
    int chara[26];
    memset(chara, 0, sizeof(chara));
    for (int i = 0; i < N; ++i)
    {
        char str[11];
        cin >> str;
        for (int j = 0; str[j] != '\0'; ++j)
            chara[str[j] - 'A']++;
    }
    for (int i = 0; i < P; ++i)
    {
        char str[200];
        cin >> str;
        for (int j = 0; str[j] != 0; ++j)
            chara[str[j] - 'A']--;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (chara[i] != 0)
            for (int j = 0; j < chara[i]; ++j)
                printf("%c", i + 'A');
    }
    cout << endl;
    return 0;
}
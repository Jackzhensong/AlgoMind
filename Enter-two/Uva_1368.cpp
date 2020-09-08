#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

const int maxm = 50 + 10;
const int maxn = 1000 + 10;
const char str[] = "TAGC";

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, n, ham = 0;
        map<char, int> mp[maxn];
        string DNA[maxm];
        cin >> m >> n;
        for(int i = 0; i < m; ++i) cin >> DNA[i];

        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < m; ++j) {
                char c = DNA[j][i];
                mp[i][c]++;
            }
            
        for(int i = 0; i < n; ++i) {
            int pos = 0, ans = 0;
            for(int j = 0; j < 4; ++j) {
                char c = str[j];
                int temp = mp[i][c];
                if(temp > ans) { ans = temp; pos = j; }
                else if(temp == ans && str[j] < str[pos])   pos = j;

                ham += (m - ans);
                printf("%c", str[pos]);
            }
        cout << endl;
        cout << ham << endl;
    }
    return 0;
}


//
const int maxm = 50 + 10;
const int maxn = 1000 + 10;
char dna[maxm][maxn];
int m, n, cnt[maxn];

void init() {
    cin >> m >> n;
    for(int i = 0; i < m; ++i) cin >> dna[i];
}

void solve() {
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int Max = 0, id;
        memset(cnt, 0, sizeof(cnt));
        for(int j = 0; j < m; ++j) {
            int tmp = dna[j][i];
            cnt[tmp]++;
            if(cnt[tmp] > Max) {
                Max = cnt[tmp];
                id = tmp;
            }
            else if(cnt[tmp] == Max && tmp < id) id = tmp;
        }
        ans += m - Max;
        printf("%c", id);
    }
    printf("\n%d\n", ans);
}

int main() {
    int cas;
    cin >> cas;
    while(cas--) {
        init();
        solve();
    }
    return 0;
}
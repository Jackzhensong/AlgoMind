#include<bits/stdc++.h>
using namespace std;

const int maxn = 9;
int n, a[maxn];

bool is_sorted() {
    for(int i = 0; i < n-1; ++i)
        if(a[i] >= a[i+1]) return false;
    return true;
}

// the number of integers with incorrect successor
int h() {
    int cnt = 0;
    for(int i = 0; i < n-1; ++i)
        if(a[i] + 1 != a[i+1]) cnt++;
    if(a[n-1] != n) cnt++;
    return cnt;
}

bool dfs(int d, int maxd) {
    if(d * 3 + h() > maxd * 3) return false;
    if(is_sorted()) return true;

    int b[maxn], olda[maxn];
    memcpy(olda, a, sizeof(a));
    for(int i = 0; i < n; ++i)
        for(int j = i; j < n; ++j) {
            // cut 
            int cnt = 0;
            for(int k = 0; k < n; ++k)
                if(k < i || k > j) 
                    b[cnt++] = a[k];
            
            // insert before position k
            for(int k = 0; k <= cnt; ++k) {
                int cnt2 = 0;
                for(int p = 0; p < k; ++p) a[cnt2++] = b[p];
                for(int p = i; p <= j; ++p) a[cnt2++] = olda[p];
                for(int p = k; p < cnt; ++p) a[cnt2++] = b[p];

                if(dfs(d+1, maxd)) return true;
                memcpy(a, olda, sizeof(a));
            }
        }
        return false;
}

int solve() {
    if(is_sorted()) return 0;
    int max_ans = 5;        // ans <= 5 for n <= 9
    for(int maxd = 1; maxd < max_ans; ++maxd)
        if(dfs(0, maxd)) return maxd;
    return max_ans;
}

int main() {
    int kase = 0;
    while(cin >> n && n) {
        for(int i = 0; i < n; ++i) 
            cin >> a[i];
        cout << "Case" << ++kase << ": " << solve() << endl;
    }
    return 0;
}
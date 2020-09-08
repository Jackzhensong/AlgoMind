#include<bits/stdc++.h>   // 埃及分数
using namespace std;

int a, b, maxd;
typedef long long LL;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 返回满足1/c <= a/b 的最小的 c
inline int get_first(LL a, LL b) {
    return b/a + 1;
}

const int maxn = 100 + 5;
LL v[maxn], ans[maxn];

// 如果当前解 v 比目前最优解ans 更优, 更新ans
bool better(int d) {
    for(int i = d; i >= 0; --i) 
        if(v[i] != ans[i]) {
            return ans[i] == -1 || v[i] < ans[i];
        }
    return false;
}

// 当前深度为 d, 分母不能小于 from, 分数之和恰好为 aa/bb
bool dfs(int d, int from, LL aa, LL bb) {
    if(d == maxd) {
        if(bb % aa)    return false;       // aa/bb 必须是埃及分数
        v[d] = bb / aa;
        if(better(d))   memcpy(ans, v, sizeof(LL) * (d + 1));
        return true;
    }

    bool ok = false;
    from = max(from, get_first(aa, bb));        // 枚举的起点
    for(int i = from; ; ++i) {         
        // 剪枝：如果剩下的maxd + 1 - d 个分数全部都是1/i, 加起来仍然不超过aa/bb, 则无解
        if(bb * (maxd + 1 - d) <= i * aa)   break;
        v[d] = i;       
        LL b2 = bb * i;            // 计算aa/bb - 1/i, 设结果为 a2/b2
        LL a2 = aa * i - bb;
        LL g = gcd(a2, b2);        // 以便约分
        if(dfs(d+1, i+1, a2/g, b2/g)) ok = true; 
    }
    return ok;
}

int main() {
    int kase = 0;
    while(cin >> a >> b) {
        int ok = 0;
        for(maxd = 1; maxd <= 100; ++maxd) {
            memset(ans, -1, sizeof(ans));
            if(dfs(0, get_first(a, b), a, b)) { ok = 1; break; }
        }
        cout << "Case " << ++ kase << ": ";
        if(ok) {
            cout << a << "/" << b << "=";
            for(int i = 0; i < maxd; ++i) 
                cout << "1/" << ans[i] << "+";
            cout << "1/" << ans[maxd] << endl;
        }
        else cout << "No solution." << endl;
    }
    return 0;
}
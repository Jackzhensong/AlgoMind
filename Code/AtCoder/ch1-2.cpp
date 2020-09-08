#include <iostream>
#include <vector>
using namespace std;

vector<int> enumerateDivisors(int M) {
    vector<int> res;
    for (int n = 1; n * n <= M; n++) {
        if (M % n == 0) {
            res.push_back(n);
            res.push_back(M / n);
        }
        if (n * n == M) {
            res.pop_back();
        }
    }
    return res;
}


int main() {
    int N, M;
    cin >> N >> M;
    int ans = 1;
    for (auto d : enumerateDivisors(M)) {
        if ((int64_t)N * d <= M) {
            ans = max(ans, d);
        }
    }
    cout << ans << endl;
    return 0;
}

//解法二
int main() {
    int n, m; cin >> n >> m; 
    //約数列挙
    vector<int> div;
    for(int k = 1; k * k <= m; k++){
        if(m % k == 0){
            div.push_back(k);
            if(m / k != k) div.push_back(m / k);
        }
    }

    int ans = 1;
    for(auto x : div){
        int rest = m / x;
        if(rest >= n) ans = max(ans, x);
    }
    cout << ans << endl;
    return 0;
}


//解法三
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int d = m / n; d >= 1; -- d){
        int ret = m / d;
        if(m % d == 0 && ret >= n){
            printf("%d\n", d);
            break;
        }
    }
    return 0;
}
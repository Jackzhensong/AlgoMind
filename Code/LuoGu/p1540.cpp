#include <vector>
#include <iostream> 
#include <algorithm>
using namespace std;

const int maxn = 1000 + 10;
int main() {
    int m, n, t, ans = 0;
    cin >> m >> n;
    vector<int> v;  // 用来表示内存
    int a[maxn];
    for(int i = 0; i < n; ++i)
        cin>>a[i];

    for(int i = 0; i < n; ++i){
        if (find(v.begin(), v.end(), a[i]) == v.end()) {   // 如果不在内存中
            v.push_back(a[i]);     // 加入内存
            ++ans;
        }
        if (v.size() > m) // 内存满了
            v.erase(v.begin()); // 把第一个单词删掉
    }
    cout << ans << endl;
}
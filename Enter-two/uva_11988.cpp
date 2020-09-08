#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int maxn = 100000 + 5;
int last, cur, Next[maxn];
char s[maxn];
 
int main(){
    while(cin>>s + 1){
        int n = strlen(s + 1);
        cout<<n<<endl;
        last = cur = 0;
        Next[0] = 0;

        for(int i=1; i <= n; ++i){
            char ch = s[i];
            if(ch == '[')   cur = 0;
            else if(ch == ']')   cur = last;
            else {
             Next[i] = Next[cur];
             Next[cur] = i;
                if(cur == last) last = i;   //更新最后一个字符编号
                cur = i;  // 移动光标
            }
        }
        for(int i = Next[0]; i != 0; i = Next[i])
            cout<<s[i];
        cout<<endl;
    }
    return 0;
}
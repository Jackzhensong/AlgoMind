#include<iostream>
#include<set>

using namespace std;
  
int main(){
    int loop = 0;
    while (cin >> loop)            
    {
        int a[1000], tem, i = 0;
        for (int i = 0; i < loop; i++)  
            cin >> a[i];
        set<int> num(a, a + loop);
        for (set<int>::iterator it = num.begin(); it != num.end(); it++){
            cout << *it << endl;
        }
    }
    return 0;
}
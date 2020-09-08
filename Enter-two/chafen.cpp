#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int k;
    while (cin >> k)
    {
        for (int y = k+1; y <= 2 * k; ++y){
            if(y*k % (y - k) == 0){
                int x = (y * k)/(y - k);
                cout<<"1/"<<k<<"="<<"1/"<<x<<"+"<<"1/"<<y<<endl;
            }
        }
    }
    return 0;
}
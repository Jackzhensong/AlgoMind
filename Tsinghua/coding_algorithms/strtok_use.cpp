#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 20;

int main() {
    
    string ptr[maxn];
    char str[] = "this, a sample string, ok my name is jacksong";
    char * p = strtok(str, " ,");
    int k = 0;
    while(p != NULL) {
        //cout << p << endl;
        ptr[k++] = p;
        p = strtok(NULL, " ,");
    }  
    for (int i = 0; i < k; ++i) cout << ptr[i] << endl;
    return 0;
}
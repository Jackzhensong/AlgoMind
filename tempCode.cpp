
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char *buf;
    gets(buf);
    int v;
    char *p = strtok(buf, ",");
    while(p) {
        cout << p << endl;
        sscanf(p, "%d", &v);
        p = strtok(NULL, ",");
    }

    return 0;
}

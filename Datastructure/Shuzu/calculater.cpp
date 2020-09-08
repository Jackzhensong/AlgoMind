#include <bits/stdc++.h>
using namespace std;

int main()
{
    int *p1, *p2;
    int n = 4;
    char *pc1, *pc2;
    p1 = (int *)100;            //地址p1为100
    p2 = (int *)200;
    cout << p2 - p1 << endl;    //输出25，因为(200-100)/sizeof(int)=100/4=25
    pc1 = (char *)p1;           //地址pc1为100
    pc2 = (char *)p2;
    cout << pc1 - pc2 << endl;     //-100,(100-200)/sizeof(char)=-100
    cout << (p2 + n) - p1 << endl; //25+4=29
}

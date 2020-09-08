#include<bits/stdc++.h>
using namespace std;

int getbit(char c, int i)
{
    return (c >> i) & 1;
}

void setbit(char &c, int i, int v)
{
    if (v)
        c |= (1 << i);
    else
        c & = ~(1 << i);
}

void flip(char &c, int i)
{
    c ^= (1 << i);
}

void output(int t,char result[])
{
    cout<<"PUZZLE #"<<t<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            cout<<getbit(result[i],j);
            if(j<5)
            cout<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    char orilights[5];    //最初灯矩阵，一个位表示一盏灯
    char lights[5];       //不停变化的灯矩阵
    char result[5];       //结果开关矩阵
    char switchs;         //某一行的开关状态
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        memset(orilights,0,sizeof(orilights));
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                int s;
                cin>>s;
                setbit(orilights[i],j,s);
            }
        }
        for(int n=0;n<64;n++){
            memcpy(lights,orilights,sizeof(orilights));
            switchs=n;
            for(int i=0;i<5;i++){
                result[i]=switchs;
                for(int j=0;j<6;j++){
                    if(getbit(switchs,j)){
                        if(j>0) flip(lights[i],j-1);
                    flip(lights[i],j);
                    if(j<5)
                        flip(lights[i],j+1);
                    }
                }
                if(i<4)
                    lights[i+1]=~switchs;
                    switchs=lights[i];
            }
            if(lights[4]==0){
                output(t,result);
                break;
            }
        }
    }
    return 0;
}
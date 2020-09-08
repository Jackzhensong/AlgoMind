#include<iostream>     //熄灯问题
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
bool isZero(int  *p, int size){
    for(int i=0; i<size; ++i){
        if(p[i] == 0) ;
        else return false;
    }
    return true;
}
void output(int p[][6], int t){
    cout<<"PUZZLE #"<<t<<endl;
    for(int i=0; i<5; ++i){
        for(int j=0; j<6; ++j){
            cout<<p[i][j];
            if(j<5)
                cout<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int t;
    cin>>t;
    int orilight[5][6];
    int light[5][6];
    int result[5][6];
    int switchs[6];
    while(t--){
        for(int i=0; i<5; ++i){
                for(int j=0; j<6; ++j){
                    cin>>orilight[i][j];
                    light[i][j] = orilight[i][j];
                }  
        }
        for(int n=0; n<64; ++n){
            
            for(int i=0; i<5; ++i){
                memcpy(result, switchs, sizeof(switchs));
                for(int j=0; j<6; ++j){
                    if(switchs[j]){
                        if(j>0)
                            ~light[i][j-1];
                        ~light[i][j];
                        if(j<5)
                            ~light[i][j+1];
                    }
                }
                if(i<4){
                    for(int j=0; j<6; ++j)
                    light[i+1][j] = light[i+1][j] ^ switchs[j];
                }
                for(int d=0; d<6; ++d)
                switchs[d] = light[i][d];
            }
            if(isZero(light[4], 6)){
                output(light, t);
                break;
            }
        }
    }
    return 0;
}
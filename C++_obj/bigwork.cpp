#include<bits/stdc++.h>
using namespace std;
int main()
{
    for(; ;){
        int choice;
        print_menu();
        cin>>choice;
        if(choice==0) break;
        if(choice==1) add();
        if(choice==2) DQ(0);
        if(choice==3) DQ(1);
        if(choice==4)   cout<<"Showing the ranklists hurts students' selfesteen";
        if(choice==5) stat();
    }
    return 0;
}
void DQ(int isp){
    char a[max1];
    for(; ;){
        cout<<"Please enter SID or name. Enter 0 to finish"<<endl;
        cin>>s;
        if(strcmp(s,0)==0) break;
        int r=0;
        for(int i=0;i<n;i++)
        if(!remove[i]){
            if(strcmp(sid[i],s)==0||strcmp(name[i],s)==0){
                if(isq) printf("%d %s %d %s %d %d %d %d %d %.2f\n",rank[i],sid[i],)
                else {remove[i]==1;r++;}
            }
        }
        if(!isq) printf("%d student(s) remove.\n",r);
    }
}
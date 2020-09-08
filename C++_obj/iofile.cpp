#include<bits/stdc++.h>
using namespace std;
class Cstudent{
    public:
        char szname[20];
        int age;
};
int main(){
    Cstudent s;
    fstream ioFile("student.dat",ios::in|ios::out);
    if(!ioFile){
        cout<<"error";
        return 0;
    }
    ioFile.seekg(0,ios::end);
    int L=0,R;
    R=ioFile.tellg()/sizeof(Cstudent)-1;
    do{
        int mid=(L+R)/2;
        ioFile.seekg(mid*sizeof(Cstudent),ios::beg);
        ioFile.read((char*)&s,sizeof(s));
        int tmp=strcmp(s.szname,"Jack");
        if(tmp=0){
            s.age=20;
            ioFile.seekp(mid*sizeof(Cstudent),ios::beg);
            ioFile.write((char*)&s,sizeof(s));
            break;
        }
        else if(tmp>0) R=mid-1;
        else L=mid+1;
    }while(L<=R);
    ioFile.close();
    return 0;
}
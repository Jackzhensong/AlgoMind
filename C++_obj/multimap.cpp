#include<bits/stdc++.h>
using namespace std;

class Cstudent {
    public:
        struct Cinfo {
            int id;
            string name;
        };
        int score;
        Cinfo info;
};

typedef multimap <int, Cstudent::Cinfo> map_std;

int main() {
    map_std mp;
    Cstudent st;
    string cmd;

    while(cin>>cmd) {
        if(cmd=="Add") {
            cin>>st.info.name>>st.info.id>>st.score;
            mp.insert(map_std::value_type(st.score,st.info));
        }

        else if(cmd=="Query") {
            int score;
            cin>>score;
            map_std::iterator p=mp.lower_bound(score);
            if(p!=mp.begin()) { 
                --p;
                score=p->first;
                map_std::iterator maxp=p;
                int maxId=p->second.id;

                for(;p!=mp.begin()&&p->first==score;--p) {
                    if(p->second.id>maxId) {
                        maxp=p;
                        maxId=p->second.id;
                    }
                }
                
                if(p->first==score) {
                    if(p->second.id>maxId) {
                    maxp=p;
                    maxId=p->second.id;
                }
            }
            cout<<maxp->second.name<<" "<<maxp->second.id<<" "<<maxp->first<<endl;
        }
        else cout<<"Nobody"<<endl;
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Ctyre{
    public:
        Ctyre() {cout<<"Ctyre constructor"<<endl;}
        ~Ctyre() {cout<<"Ctyre destructor"<<endl;}
};
class Cengine {
    public:
        Cengine() {cout<<"Cengine constructor"<<endl;}
        ~Cengine() {cout<<"Cengine  destructor"<<endl;}
};
class Ccar{
    private:
        Cengine engine ;
        Ctyre tyre;
    public:
        Ccar() {cout<<"Ccar constructor"<<endl;}
        ~Ccar() {cout<<"Ccar  destructor"<<endl;}
};

int main(){
    Ccar car;
    return 0;
}
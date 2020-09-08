#include<bits/stdc++.h>
using namespace std;
class Cshape {
    public:
        virtual double Area(){};
        virtual void PrintInfo() {};
};
class Crectangle:public Cshape{
    public:
        int w,h;
        virtual double Area ();
        virtual void PrintInfo();
};
class Ccircle :public Cshape{
    public:
        int r;
        virtual double Area();
        virtual void PrintInfo();
};
class Ctriangle:public Cshape{
    public:
        int a,b,c;
        virtual double Area();
        virtual void PrintInfo();
};
double Crectangle::Area (){
    return w*h;
}
void Crectangle::PrintInfo(){
    cout<<"rectangle:"<<Area()<<endl;
}
double Ccircle::Area(){
    return 3.14*r*r;
}
void Ccircle::PrintInfo(){
    cout<<"circle:"<<Area()<<endl;
}

double Ctriangle::Area(){
    double p=(a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

void Ctriangle::PrintInfo(){
    cout<<"triangle:"<<Area()<<endl;
}
Cshape *pshape[100];
int Mycompare(const void *s1,const void *s2){
    Cshape **p1=(Cshape **)s1;
    Cshape **p2=(Cshape **)s2;
    double a1=(*p1)->Area();
    double a2=(*p2)->Area();
    if(a1<a2) return -1;
    else if(a2<a1) return 1;
    else return 0;
}
int main (){
    int i,n;
    Crectangle* pr;
    Ccircle* pc;
    Ctriangle* pt;
    cin>>n;
    for(i=0;i<n;i++){
        char c;
        cin>>c;
        switch(c){
            case 'R': pr=new Crectangle();
            cin>>pr->w>>pr->h;
            pshape[i]=pr;
            break;
            case 'C': pc=new Ccircle();
            cin>>pc->r;
            pshape[i]=pc;
            break;
            case 'T': pt=new Ctriangle();
            cin>>pt->a>>pt->b>>pt->c;
            pshape[i]=pt;
            break;
        }
    }
    qsort (pshape,n,sizeof(Cshape*),Mycompare);
    for(i=0;i<n;i++){
        pshape[i]->PrintInfo();
        delete pshape[i];
    }
    return 0;
}

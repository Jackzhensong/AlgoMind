#include<bits/stdc++.h>
using namespace std;
/*class CMyclass
{
   public:
     CMyclass(){};
     CMyclass(CMyclass &c){
          cout << "copy constructor" << endl;
     }
     ~CMyclass(){
          cout << "destructor" << endl;
     }
};
void fun(CMyclass obj_){
     cout << "fun" << endl;
}
CMyclass c;
CMyclass Test(){
     cout << "test" << endl;
     return c;
}

int main()
{
     CMyclass c1;
     fun(c1);
     Test();
     return 0;
}*/
/*class A
{
	public:
	int x;
	int getX() { return x; }	
};
void swap(A &a,A &b)
{
	int  tmp = a.x;
	a.x = b.x;
	b.x = tmp;
}
int main()
{
	A a,b;
	a.x = 3;
	b.x = 5;
	swap(a,b);
	cout << a.getX() << "," << b.getX();
	return 0;
}

class Student {
     char name[20];
     int age;
     int id;
     int scores[5];
     public:
     int input(){
         char buf[200];
         cin.getline(buf,200);
         char* p=strtok(buf,",");
         strcpy(name,p);
         p=strtok(NULL,",");
         age=atoi(p);
         p=strtok(NULL,",");
         id=atoi(p);
         for(int i=0;i<4;++i){
              p=strtok(NULL,",");
              scores[i]=stoi(p);
         }
     }
     double calculate(){
          double sum=0;
          for(int i=0;i<4;++i)
          sum+=scores[i];
          return sum/4.0;
     }
     void output(){
          cout<<name<<","<<age<<","<<id<<","<<calculate()<<endl;
     }
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}*/


#include <iostream>
using namespace std;
// 在此处补充你的代码
class Animal{
     public:
     static int number;
     Animal() { number++; }
     virtual ~Animal() { number--; }
};

class Dog:public Animal{
     public:
     static int number;
     Dog():Animal() { number++;}
     virtual ~Dog() { number--;}
};

class Cat:public Animal{
     public:
     static int number;
     Cat():Animal() { number++;}
     virtual ~Cat() { number--; }
};
int Animal::number=0;
int Dog::number=0;
int Cat::number=0;
void print() {
	cout << Animal::number << " animals in the zoo, " 
          << Dog::number << " of them are dogs, " 
          << Cat::number << " of them are cats" << endl;
}

int main() {
	print();
	Dog d1, d2;
	Cat c1;
	print();
	Dog* d3 = new Dog();
	Animal* c2 = new Cat;
	Cat* c3 = new Cat;
	print();
	delete c3;
	delete c2;
	delete d3;
	print();
}



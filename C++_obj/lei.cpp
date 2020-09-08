#include <bits/stdc++.h>
using namespace std;
class employee
{
  private:
    char sename[30];
    public:
    int salary;

  public:
    void setname(char *name);
    void getname(char *name);
    void averageSalary(employee e1, employee e2);
};
void employee ::setname(char *name)
{
    strcpy(sename, name);
}

void employee ::getname(char *name)
{
    strcpy(name, sename);
}

void employee ::averageSalary(employee e1, employee e2)
{
    salary = (e1.salary + e2.salary) / 2;
}

int main()
{
    employee e;
    e.setname("Tom");
    e.salary = 5000;
    cout<<e.salary<<endl;
    return 0;
}
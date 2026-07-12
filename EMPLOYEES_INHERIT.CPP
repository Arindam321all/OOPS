#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
// Base class for single Inheritance
class Employee{
    protected:
        string name;
        int employeeID;
    public:
    Employee(string empname,int empID):name(empname),employeeID(empID){
        cout << __FUNCTION__ << endl;
    }
    void display()const{
        cout << "Employee: " << name << ", ID: " << employeeID << endl;
    }
};
// Derived class for single inheritance
class Developer:public Employee{
private:
    string programminglanguage;
public:
Developer(string empname,int empID,string plang):Employee(empname,empID),programminglanguage(plang){}
void show(){
    display();
    cout << "specialization: Developer, programming Language  " <<
    programminglanguage << endl;
}
};

int main(){
    Employee A("ramu", 1);
    A.display();
    return 0;
}
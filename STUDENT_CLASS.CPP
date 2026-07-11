#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353

class Student{
    public:
        //Attributes
        int id;
        int age;
        string name;
        int nos;

        // constructor(ctor):their is also one default constructor
        Student(){
            cout << "student ka default ctor called" << endl;
        }

        //Behaviour/Methods/Functions
        void study(){
            cout <<this->name<< "is studying" << endl;
        }
        void sleep(){
            cout <<this->name<< "is Sleeping" << endl;
        }
        void bunk(){
            cout <<this->name << "is Bunking" << endl;
        }

        // Destructor: default dtor
        
        ~Student(){
            cout << "student ka default dtor" << endl;
        }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    Student A;
    A.id = 1;
    A.name = "ranu";
    A.nos = 6;
    A.age = 15;
    A.study();
    return 0;
}
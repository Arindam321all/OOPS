#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353

class Student{
    public:
        //Attributes
        int id;
        
        string name;
        int nos;
    private:
        int age;
        int *gpa;
        string gf;

    public:
        // constructor(ctor):their is also one default constructor
        Student(){
            cout <<"student ka default ctor called" << endl;
        }
        // constructer:parameterised ctor
        Student(int id,int age,string name,int nos,float gpa,string gf){
            cout << "student parameterised ctor called" << endl;
            this->id = id;
            this->age=age;
            this->name = name;
            this->nos = nos;
            this->gpa = new int(gpa);
            this->gf = gf;
        }
        // copy constucter:copy ctor
        Student (const Student &srcobj){
            cout << "copy ctor call" << endl;
            this->id = srcobj.id;
            this->age = srcobj.age;
            this->name = srcobj.name;
            this->nos = srcobj.nos;
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
            cout <<"student ka default dtor" << endl;
            delete this->gpa;
        }
    private:
        void gfchatting(){
            cout << this->name << " chatting with gf" << endl;
        }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    Student A(1,15,"ranu",6,9.9,"sanu");
    
    return 0;
}
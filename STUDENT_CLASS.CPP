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
        int *gpa;

        // constructor(ctor):their is also one default constructor
        Student(){
            cout <<"student ka default ctor called" << endl;
        }
        // constructer:parameterised ctor
        Student(int id,int age,string name,int nos,float gpa){
            cout << "student parameterised ctor called" << endl;
            this->id = id;
            this->age=age;
            this->name = name;
            this->nos = nos;
            this->gpa = new int(gpa);
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
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // Student A;
    // A.id = 1;
    // A.name = "ranu";
    // A.nos = 6;
    // A.age = 15;
    // A.study();
    // Student A(1, 15, "Rahul", 6);
    // Student B(2, 61, "Ranu", 6);
    Student C(3, 32, "alice", 8,9.8);
    Student D = C;
    cout << D.name << " " << C.name << endl;
    Student E(D);
    cout << E.name << endl;

    // Dynamic Allocation or Student pointer
    // Student *R = new Student(2, 45, "rik", 6);
    // cout << R->name<<" ," << R->age <<","<< R->id << endl;
    // delete R;// dynamic allocation me khudse dtor ko call kna padta hain
    return 0;
}
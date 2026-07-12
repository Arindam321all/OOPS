#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
class vehicle{
    protected:
        string name;
        string model;
        int notyres;
    public:
        vehicle(string _name, string _model, int _notyres)
        {
            this->name = _name;
            this->model = _model;
            this->notyres = _notyres;
            cout << "vehicle ctor called" << endl;
        }
    
    string getname(){
        return this->name;
    }
    void startengyne(){
        cout << "engyne is starting " <<this-> name << " " << model << endl;
    }
    void stopengyne(){
        cout << "engyne is stopping " << name << " " << model << endl;
    }
    ~vehicle(){
        cout << "vehicle dtor called" << endl;
    }
};
class car:public vehicle{
    protected:
        int nodoors;
        string transmission;
    public:
    car(string _name,string _model,int _notyres,int _nodoors,string _transmission):vehicle(_name,_model,_notyres){
        
        this->nodoors = _nodoors;
        this->transmission = _transmission;
        cout << "car ctor called" << endl;
    }
    
    void startac(){
        cout << "AC has started of" << getname() << endl;
    }
    ~car(){
        cout << "car dtor called" << endl;
    }
};
class motorcycle:public vehicle{
    protected:
        string handlestyle;
        string suspension_type;
    public:
    motorcycle(string _name,string _model,int _notyres,string _handlestyle,string _suspension_type):vehicle(_name,_model,_notyres){
        this->handlestyle = _handlestyle;
        this->suspension_type = _suspension_type;
        cout << "motorcycle ctor called"<<endl;
    }
    
    void wheelie(){

    }
    ~motorcycle(){
        cout << "motorcycle dtor called" << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    car A("Maruti 800", "LXI", 4, 4, "Manual");
    A.startengyne();
    A.startac();
    A.stopengyne();
    return 0;
}
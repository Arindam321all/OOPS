#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
class Add{
    public:
    //x,y. two int addition
    int sum(int x,int y){
        cout << "sum of 2 int" << endl;
        return x + y;
    }
    //x,y,z , three int add
    int sum(int x,int y,int z){
        cout << "sum of 3 int" << endl;
        return x + y +z;
    }
    double sum(double x,double y){
        cout << "sum of 2 doubles" << endl;
        return x + y;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int x = 5, y = 5,z=4;
    Add add;
    cout<<add.sum(x, y)<<endl;
    cout << add.sum(x, y, z) << endl;
    cout << add.sum(5.9, 8, 1);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353

class Shape{
    public:
        void draw(){
            cout << "shape is drawing" << endl;
        }
};
class Circle:public Shape{
    public:
        void draw(){
            cout << "circle is drawing" << endl;
        }
};
class Rectangle:public Shape{
    public:
    void draw(){
        cout << "Rectangle is drawing" << endl;
    }
};
void ShapeDrawing(Shape *s){
    s->draw();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    Rectangle c;
    ShapeDrawing(&c);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353

class Shape{
    public:
        virtual void draw(){
            cout << "generative is drawing" << endl;
        }
};
class Circle:public Shape{
    public:
        void draw()override{
            cout << "circle is drawing" << endl;
        }
};
class Rectangle:public Shape{
    public:
    void draw()override{
        cout << "rectangle is drawing" << endl;
    }
};
class triangle:public Shape{
    public:
    void draw()override{
        cout << "triangle is drawing" << endl;
    }
};
void showdrawing(Shape *s){
    s->draw(); // draw is polymorphic;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // Circle c;  //in  stack
    // Rectangle *r = new Rectangle();//in HEAP
    // showdrawing(&c);
    // showdrawing(r);

    //w/o virtual keyword
    Shape *s = new Shape();
    s->draw();
    //UPCASTING
    // Shape *s = new Circle();
    // s->draw();

    // Circle *c = new Circle();
    // c->draw();

    // DOWNCASTING
    Shape *s2 = new Shape();
    Circle *c2 = (Circle *)s2;
    c2->draw();
    return 0;
}
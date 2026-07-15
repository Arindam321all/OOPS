#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353

class Complex{
    public:
        int real;
        int imag;
        Complex(){
            real = imag = -1;
        }
        Complex(int r, int i) : real(r), imag(i) {};
        // // syntax
        // ret_type operator <op> (args){
        //     // kaam
        //     // return <>
        // }
        Complex operator+(const Complex &B){
            Complex temp;
            temp.real = this->real + B.real;
            temp.imag = this->imag + B.imag;
            return temp;
        }
        Complex operator-(const Complex &B){
            Complex temp;
            temp.real = this->real - B.real;
            temp.imag = this->imag - B.imag;
            return temp;
        }
        bool  operator==(const Complex &B){
            bool a = this->real == B.real;
            bool b = this->imag == B.imag;
            return a == b;
        }
        
        void print(){
            printf("[%d + i%d]\n", this->real, this->imag);
        }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    Complex A(2,5);
    A.print();
    Complex B(2, 3);
    B.print();
    Complex C = A + B;
    C.print();
    Complex D = A - B;
    D.print();
    bool a = A == B;
    cout << a << endl;
    return 0;
}
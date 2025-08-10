#include<iostream>
using namespace std;

//Hierarchial
class A{
    public:
    void func(){
        cout<<"Inside class A"<<endl;
    }
};

//class B: public A{
class B{
    public:
    void func(){
        cout<<"Inside class B"<<endl;
    }
};

class C: public A{
    public:
    void funcC(){
        cout<<"Inside class C"<<endl;
    }
};

//Ambiguity
class D: public A, public B{
    
};

int main(){
    // A a;
    // a.funcA();

    // B b;
    // b.funcA();
    // b.funcB();

    // C c;
    // c.funcA();
    // c.funcC();

    D d;
    d.A::func();
    d.B::func();
}
#include<iostream>
using namespace std;

//Function Overloading
class A{
    public:
    void sayHello(){
        cout<<"Hello"<<endl;
    }

    int sayHello(int n){
        cout<<"Hello"<<endl;
        return n;
    }

    void sayHello(string name){
        cout<<"Hello "<<name<<endl;
    }
};  

//Operator Overloading
class B{
    public:
    int a;
    int b;

    int add(){
        return a+b;
    }

    //Synatx: return_type operator[op] (class &obj)
    void operator+ (B &b){
        int val1 = this->a;
        int val2 = b.a;
        cout<<val2-val1<<endl;
    }
};

//Method Overriding
class Animal{
    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
};

class Dog: public Animal{
    public:
    void speak(){
        cout<<"Barking"<<endl;
    }
};

int main(){

    Dog d;
    d.speak();
    

    /*
    B b;
    b.a = 1;
    b.b = 2;
    cout<<b.add()<<endl;

    B a, b;
    a.a = 4;
    b.a = 7;
    a + b;

    A a;
    a.sayHello();
    a.sayHello("XYZ");
    a.sayHello(4);
    */
}
#include<iostream>
using namespace std;

class Animal{
    public:
    int age;
    int weight;

    void bark(){
        cout<<"Animal Barking"<<endl;
    }
};

class Human{
    public:
    string color;

    void speak(){
        cout<<"Human Speaking"<<endl;
    }
};

//Multiple
class Hybrid: public Human, public Animal{

};

//Single
class Dog: public Animal{

};

//Multilevel
class Puppy: public Dog{

};

int main(){
    Puppy p;
    p.bark();
    cout<<p.age<<endl;

    Hybrid h;
    h.speak();
    h.bark();
}
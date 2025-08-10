#include<iostream>
using namespace std;

class Human{
    private:
    int age;

    public:
    int height;
    int weight;

    public:
    int getAge(){
        return this->age;
    }

    void setWeight(int w){
        this->weight = w;
    }
};

class Male: private Human{
    public:
    string color;

    void sleep(){
        cout<<"Male Sleeping"<<endl;
    }

    int getHeight(){
        return this->height;
    }
};

int main(){
    Male m1;
    cout<<m1.getHeight()<<endl;
}
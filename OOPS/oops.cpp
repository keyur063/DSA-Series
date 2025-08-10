#include<iostream>
#include<string.h>
// #include "Hero.cpp"
using namespace std;

class Hero{
    //properties/ state
    private:
    int health;

    public:
    char level;
    char* name;
    static int timeToComplete;

    //Simple Constructor
    Hero(){
        cout<<"Simple Constructor called"<<endl;
        name = new char[100];
    }

    //Parameterized Constructor
    Hero(int health){
        cout<<"this->"<<this<<endl;
        this->health = health;
    }

    Hero(int health, char level){
        this->health = health;
        this->level = level;
    }

    //Copy Constructor -> Deep Copy
    Hero(Hero& h){
        char* ch = new char[strlen(h.name) + 1];
        strcpy(ch, h.name);
        this->name = ch;

        cout<<"Copy Constructor called"<<endl;
        this->health = h.health;
        this->level = h.level;
    }

    //methods/ behaviour
    void print(){
        cout<<endl;
        cout<<"[ Name: "<<this->name<<" , ";
        cout<<"Health: "<<this->health<<" , ";
        cout<<"Level: "<<this->level<<" ]"<<endl;
        cout<<endl;
    }

    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health = h;
    }

    void setLevel(char ch){
        level = ch;
    }

    void setName(char name[]){
        strcpy(this->name, name);
    }


    /*Static Function-
    Access only static data memebers
    No object -> no pointer to object -> no this keyword
    */
    static int random(){
        return timeToComplete;
    }


    ~Hero(){
        cout<<"Destructor called"<<endl;
    }
};

/*
static keyword is used to access data member which belongs to class without creating object
Syntax: datatype className:: variableName = value;
*/
int Hero :: timeToComplete = 5;

int main(){

    
    cout<<Hero::timeToComplete<<endl;
    cout<<Hero::random()<<endl;
    /*
    Hero a;
    cout<<a.timeToComplete<<endl; //not recommended

    Hero b;
    b.timeToComplete = 10;
    cout<<a.timeToComplete<<endl; //10
    cout<<b.timeToComplete<<endl; //a=b as object independent variable
    */



    /*
    Hero a; //automatic destructor call for static allocation
    Hero* b = new Hero();
    delete b; //manual destructor call for dynamic allocation

    Hero h1;
    h1.setHealth(70);
    h1.setLevel('B');
    char name[5] = "Jack";
    h1.setName(name);
    // h1.print();

    //Default Copy Constructor -> Shallow Copy as address is same
    //Custom Copy Constructor -> Deep Copy
    Hero h2(h1); //or Hero h2 = h1
    // h2.print();

    h1.name[3] = 'q';
    h1.print();
    h2.print();

    h1 = h2;
    h1.print();
    h2.print();
    */




    /*
    Hero a(10);
    cout<<"Address of a: "<<&a<<endl;
    cout<<a.getHealth()<<endl;

    Hero* b = new Hero;

    Hero c(11, 'B');
    cout<<c.getHealth()<<endl;
    cout<<c.getLevel()<<endl;
    
    //Copy Constructor
    Hero S(70, 'C');
    S.print();

    Hero T(S);
    T.print();
    */

    /*
    //static allocation
    Hero a;
    a.setHealth(70);
    a.setLevel('A');
    cout<<a.level<<endl;
    cout<<a.getHealth()<<endl;

    //dynamic allocation (address in heap)
    Hero* b = new Hero;
    b->setHealth(80);
    b->setLevel('B');

    cout<<"Method 1:"<<endl;
    cout<<(*b).level<<endl;
    cout<<(*b).getHealth()<<endl;

    cout<<"Method 2:"<<endl;
    cout<<b->level<<endl;
    cout<<b->getHealth()<<endl;

    Hero h1;
    cout<<h1.getHealth()<<endl; //garbage value
    h1.setHealth(70);
    cout<<h1.getHealth()<<endl;

    cout<<h1.getLevel()<<endl; //garbage value
    h1.setLevel('A');
    cout<<h1.getLevel()<<endl;

    h1.health = 70;
    h1.level = 'A';

    cout<<"Size of class Hero: "<<sizeof(h1)<<endl; //1 when empty
    */
}
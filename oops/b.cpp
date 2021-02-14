// Topics covered

// 1. polymorphism(runtime)
// 2. Encapsulation (used for data hiding and data pretection for security reason)
// 3. Abstraction(Used also for data hiding but for complexity reason)

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const ll MOD = 1e9 + 7;
const ll N = 1e5 + 5;

class person
{
    public:
        string name;
        int age;
        static int count;
    
        person() 
        {
            count++;
            // cout << "Constructor called" << endl;
        }

        person(string name, int age)
        {
            person(); // calling a default constructor
            this->name = name; // this->name points to the data member of this class
            this->age = age;
        }

        void walk() // method 
        {
            cout << name << " is walking" << endl;
        }    
        void eat() // method 
        {
            cout << name << " is eating" << endl;
        }
        void walk(int steps) // method
        {
            cout << name << " walked"  << steps  << "steps" << endl;
        }
        static int getCount() // static member function
        {
            return count;
        }
};


// <-------inheritance------>

//child class has all the properties of parent class 
//here child class - developer and parent class - person

class developer:public person
{
    public: 
        developer(string name, int age) : person(name, age) // calling the parent constructor
        {   
        }

        // <-----------POLYMORPHISM(Run Time)------------->
        //from which class the walk function will be called is decided on runtime 
        //therefore it is called runtime polymorphism
        void walk() // method 
        {
            cout << "developer " << name << " is walking" << endl;
        }    
        // <-----------POLYMORPHISM(Run Time)------------->
};

// <-------inheritance------>
    
//<--------Encapsulation-------->
class laptop
{
    //if we want that only some people can set the price than we have to
    //make price data member private and set the price in the class itself.
    public: 
        int ram;
        void setPrice(int p)
        {
            // here you can check if the user is admin or not something like that 
            bool isAdmin = true;
            if(isAdmin)
            {
                this->price = p;
            }
            else
            {
                cout << "User is not an admin" << endl;
            }
        }
        int getPrice()
        {
            return this->price;
        }
    private:
        int price;


};
//<--------Encapsulation-------->

abstract class

int person::count = 0; // intialize static count to count the number of objects 

int main()
{
    IOS;

    person p1, p2("abcd", 20), p3; // creates the object of person class
    developer d1("Vishwa", 21);
    cout << d1.name << endl;
    cout << d1.age << endl;
    d1.walk();
    d1.eat();

    //<--------Encapsulation-------->
    laptop l1;
    l1.setPrice(40);
    cout << l1.getPrice() << endl;
    // cout << "laptiop price " << l1.price << endl;
    //<--------Encapsulation-------->

    return 0;   
}
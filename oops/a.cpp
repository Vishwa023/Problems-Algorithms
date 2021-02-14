
//Topic covered

// 1. class and objects
// 2. constructor
// 3. static
// 4. polymorphism(complile time)


#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const ll MOD = 1e9 + 7;
const ll N = 1e5 + 5;

// <------- Class and object ----->
//class is the blueprint and we can create many objects with that blueprint
//Ex : Blueprint of the house(which is class which has properties and behaviours) and we can 
//create many houses of that blueprint (here house is the object)
//Here behaviours means methods (functions).
// <------- Class and object ----->

class person
{
    public:
        string name;
        int age;
        static int count;
        
        // <------Constructor------->
        // Constructor is used to create an object and it return the object 
        person() 
        {
            count++;
            cout << "Constructor called" << endl;
        }

        //override constructor which helps to initialize the data members
        person(string name, int age)
        {
            person(); // calling a default constructor
            this->name = name; // this->name points to the data member of this class
            this->age = age;
        }
        // <------Constructor------->

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

int person::count = 0; // intialize static count to count the number of objects 

int main()
{
    IOS;

    person p1, p2("abcd", 20), p3; // creates the object of person class
    p1.name = "vishwa";
    p1.age = 22;

    cout << p2.name << endl;
    cout << p2.age << endl;

    //<-------POLYMORPHISM------------>
    p1.walk();
    p1.walk(12);
    //Here two walk functions are example of polymorphism 
    //As we can see if we invoke walk function without any 
    //argument then it will call walk function which does 
    //not have any argument this shows the same function can behave
    //differently in different situation and which function will be 
    //called is decide at the time of the compilation of the program 
    //for this reason it is called complile time polymorphism.
    //<-------POLYMORPHISM------------>
    
    // <---------static---------------->
    // count the number of objects created  
    //we can say static is the global variable of the class
    //static member function is used to access or manipulate the static data member
    //other data member can not access in static memeber function
    cout << person::count << endl; 
    cout << person::getCount() << endl;
    // <---------static---------------->    
    return 0;   
}
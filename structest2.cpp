#include <iostream>
using namespace std;

struct Human{
    char name [50];
    int age;
    float salary;
};

int main(){
    Human h1; //struct Human h; =---> both are the same though struct is the old style of doing it. Human h1 is a lot more common 
    //as it is modnernized.
    
    cout << "Enter Full name: ";
    cin.get(h1.name, 50);
    cout << "Enter age: "; cin >> h1.age;
    cout << "Enter salary: "; cin >> h1.salary;
    cout << "Age: "<< h1.age << endl;
    cout << "Salary: " << h1.salary;

    return 0;
    
}
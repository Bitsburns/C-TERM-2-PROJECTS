#include <iostream>
using namespace std;

struct Human{
    char name[50];
    int age;
    float salary;
};

void displayData(Human);

int main(){
    Human h1;
    
    cout << "Enter Full Name: ";
    cin.get(h1.name, 50);

    cout << "Enter age: ";
    cin >> h1.age;

    cout << "Enter salary: ";
    cin >> h1.salary;

    displayData(h1);
    return 0;

}

void displayData(Human h1){

    cout << "Display information... " << endl;
    cout << "Full Name: " << h1.name << endl;
    cout << "Age: " << h1.age << endl;
    cout << "Salary: " << h1.salary;
    
}
#include <iostream>
using namespace std;

int main(){

    float avg, sum = 0;

    float grades[10]; 

    cout << "Input 10 grades from 10 students: ";

    for(int a = 0; a < 10; a++){
        cin >> grades[a];
    }

    float length = sizeof(grades) / sizeof(grades[0]);

    for (float score : grades) {
        sum += score;
    }

    avg = sum / length;

    cout << "The average score is: " << avg << "\n";

    return 0;
}
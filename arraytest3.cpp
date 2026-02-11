// This is the array from arraytest1 + functions

#include <iostream>
using namespace std;

void theGrades(float arr[], int size);
float average(float arr[], int size);

void theGrades(float arr[], int size){
    for(int a = 0; a < size; a++){
        cin >> arr[a];
    }
    
};

float average(float arr[], int size){
    float sum = 0;
    for(int i = 0; i < size; i++){
        sum+=arr[i];
    }

    return sum / size;
};


int main(){
    //float studGrades[10]; /// Currently in this code you can only type 10 values in
    //int elements = 10;

    float studGrades[100];
    int elements = 100;  //This method adds 100 elements (max size) and are usually used by the beginner users.

    /*int size;
    cin >> size;
    vector<float> studGrades(size); // This one creates a vector depending the user's inputted size*/


    cout << "Enter student grades: ";
    theGrades(studGrades, elements);

    float avg = average(studGrades, elements);

    cout << "The average of the student's score are: " << avg;
    return 0;
}

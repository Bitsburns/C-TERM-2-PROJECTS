// This method is similar to arraytest3 code however it uses modernized vectors for C++. Not necessary for exams however it could be useful


#include <iostream>
#include <vector> // 1. Include the vector library
using namespace std;

// 2. Update prototypes to take a vector. 
// We use '&' to modify the original vector, not a copy.
void inputGrades(vector<float>& arr);
float calculateAverage(const vector<float>& arr); // 'const' means we won't change data here

// Function to get input
void inputGrades(vector<float>& arr) {
    cout << "Enter " << arr.size() << " student grades:\n";
    // We can use the vector's .size() method directly!
    for(int a = 0; a < arr.size(); a++){
        cin >> arr[a]; // Works just like an array!
    }
}

// Function to calculate average
float calculateAverage(const vector<float>& arr) {
    float sum = 0;
    // Modern "Range-based for loop" works perfectly with vectors
    for(float score : arr) {
        sum += score;
    }
    return sum / arr.size(); // No need to pass 'size' separately
}

int main(){
    int numStudents;

    // 3. Ask the user for the size FIRST
    cout << "How many students do you have? ";
    cin >> numStudents;

    // 4. Create the vector with that exact size
    // This is the "Magic Backpack" created at the perfect size
    vector<float> studGrades(numStudents);

    // 5. Pass the whole vector. It carries its size information with it.
    inputGrades(studGrades);

    float avg = calculateAverage(studGrades);

    cout << "The average score is: " << avg << "\n";

    return 0;
}
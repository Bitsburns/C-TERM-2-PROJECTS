#include <iostream>
#include <cstring> // Required for C-string functions like strcpy

using namespace std;

// 1. STRUCT definition
// This acts like a blueprint for a new data type called 'Student'
struct Student {
    char name[50]; // C-String: An array of characters ending with a null terminator (\0)
    int id;
    float gpa;
};

// 2. FUNCTION prototypes
// These tell the compiler that these functions exist, even if we define them later.
void printStudent(Student s);
void initializeStudent(Student& s, const char* newName, int newId, float newGpa);

int main() {
    // 3. ARRAY of Structs
    // We are creating a list capable of holding 3 Student structures.
    Student classRoster[3];

    // Let's populate our array using a helper function
    // We pass individual array elements (which are Students) to the function
    initializeStudent(classRoster[0], "Alice Smith", 1001, 3.8);
    initializeStudent(classRoster[1], "Bob Jones", 1002, 2.5);
    initializeStudent(classRoster[2], "Charlie Day", 1003, 3.2);

    cout << "--- Class Roster ---" << endl;

    // Loop through the array and print each student
    for (int i = 0; i < 3; i++) {
        printStudent(classRoster[i]);
    }

    return 0;
}

// Function Definitions

// This function takes a Student struct by "reference" (note the &)
// This allows the function to modify the actual variable passed to it.
void initializeStudent(Student& s, const char* newName, int newId, float newGpa) {
    // dealing with C-strings often requires specific functions like strcpy (string copy)
    // We cannot simply say: s.name = newName;
    strcpy(s.name, newName); 
    
    s.id = newId;
    s.gpa = newGpa;
}

// This function takes a Student struct by "value"
// It creates a copy of the data just for printing, protecting the original data.
void printStudent(Student s) {
    cout << "ID: " << s.id << " | Name: " << s.name << " | GPA: " << s.gpa << endl;
}
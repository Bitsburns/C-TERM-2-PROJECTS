#include <iostream>
using namespace std;

// This function takes a COPY (Pass by Value)
void failToChange(int number) {
    number = 999; // This only changes the copy inside this function
}

// This function takes the ORIGINAL (Pass by Reference)
// Notice the '&' symbol!
void actuallyChange(int& number) {
    number = 999; // This changes the real variable in main()
}

int main() {
    int myScore = 50;

    // Try to change it with Pass by Value
    failToChange(myScore);
    cout << "Score after failToChange: " << myScore << endl; // Prints 50 (Unchanged)

    // Try to change it with Pass by Reference
    actuallyChange(myScore);
    cout << "Score after actuallyChange: " << myScore << endl; // Prints 999 (Changed!)

    return 0;
}
#include <iostream>
#include <cstring> // Required for all these functions

using namespace std;

int main() {
    // --- 1. strcpy & strcat ---
    
    char buffer[50]; // Make this BIG enough for everything we plan to do
    char firstName[] = "John";
    char lastName[] = "Smith";

    // strcpy: "Copy 'John' into the buffer"
    // Buffer acts like a blank slate here.
    strcpy(buffer, firstName); 
    cout << "After strcpy: " << buffer << endl; // Output: John

    // strcat: "Add a space to the end of whatever is currently in buffer"
    strcat(buffer, " "); 
    
    // strcat: "Add 'Smith' to the end"
    strcat(buffer, lastName);
    cout << "After strcat: " << buffer << endl; // Output: John Smith


    // --- 2. strncpy & strncat (The 'Safe' Versions) ---

    char limitedBuffer[10]; // Tiny buffer!
    
    // strncpy: Let's only copy the first 3 letters of "University"
    // NOTE: This does NOT put a \0 at the end because we hit the limit '3'
    strncpy(limitedBuffer, "University", 3);
    
    // CRITICAL STEP: Manually close the string
    limitedBuffer[3] = '\0'; 
    cout << "After strncpy: " << limitedBuffer << endl; // Output: Uni

    // strncat: Let's append just 2 letters from a new word
    // This helper AUTOMATICALLY adds the \0 at the end.
    strncat(limitedBuffer, "verse", 2); 
    cout << "After strncat: " << limitedBuffer << endl; // Output: Unive

    return 0;
}
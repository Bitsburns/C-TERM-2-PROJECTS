#include <iostream>
using namespace std;

struct Rectangle{
    int width, height;
};

int main(){
    struct Rectangle a;
    a.width = 10;
    a.height = 5;
    cout << "Area is: " << (a.width*a.height) << endl;
    return 0;
}
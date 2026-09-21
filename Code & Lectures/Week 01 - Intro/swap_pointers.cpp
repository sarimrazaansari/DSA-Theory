#include <iostream>
using namespace std;

// function prototype with pointers as parameters
void swap(float*, float*);

int main() {

    // initialize variables
    float x = 15, y = 65;

    cout << "Before swapping" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    // call function by passing variable addresses
    swap(&x, &y);

    cout << "\nAfter swapping" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    
    return 0;
}

// function definition to swap floating-point numbers
void swap(float* num1, float* num2) {
    float temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}


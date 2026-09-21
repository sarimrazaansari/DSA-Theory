#include <iostream>
using namespace std;



// Class definition
class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor with parameters
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    // Copy constructor
    Rectangle(const Rectangle& other) {
        this->length = length;
        width = other.width;
    }

    // Member function to calculate area
    double calculateArea() {
        return length * width;
    }

    // Member function to display dimensions
    void displayDimensions() {
        cout << "Length: " << length << " Width: " << width << endl;
    }
};

int main() {
    // Create a Rectangle object with a constructor
    Rectangle myRectangle(5.0, 3.0);

    // Create another Rectangle object using the copy constructor
    Rectangle copyOfRectangle(myRectangle);

    // Call member functions to perform operations
    cout << "Original Rectangle:" << endl;
    myRectangle.displayDimensions();
    cout << "Area: " << myRectangle.calculateArea() << endl;

    cout << "\nCopied Rectangle:" << endl;
    copyOfRectangle.displayDimensions();
    cout << "Area: " << copyOfRectangle.calculateArea() << endl;

    return 0;
}


#include <iostream>
#include <string.h>
using namespace std;
class book {
    string title;
    string author;
 
public:
    book(string, string);
    book(book& t) // copy constructor
    {
        title = t.title;
        author = t.author;
        cout<<"Copy constructor is called";

    }
    void display();
};
book::book(string n , string a)
{
    title = n;
    author = a;
}
void book::display()
{
    cout << endl << title << "\t" << author;
}
int main() {
    book originalBook("The Catcher in the Rye", "J.D. Salinger");
    originalBook.display();

    // Using the copy constructor to create a copy
    book copiedBook = originalBook;
    copiedBook.display();

    return 0;
}

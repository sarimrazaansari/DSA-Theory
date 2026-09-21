#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    
    int* ptr = arr;  // Points to first element

    for (int i = 0; i < 5; i++) {
        cout << "Element " << i << " = " << *(ptr + i) << endl;
    
	}
cout<<*arr;
    return 0;
}


#include <iostream>
using namespace std;

int main()
{
    int rows = 3;

    // 3 row pointers create kar rahe hain
    int **arr = new int*[rows];
    
    // Har row ki different size
    arr[0] = new int[2];   // Row 0 mein 2 elements
    arr[1] = new int[4];   // Row 1 mein 4 elements
    arr[2] = new int[3];   // Row 2 mein 3 elements

    // Values assign kar rahe hain
    arr[0][0] = 10;
    arr[0][1] = 20;

    arr[1][0] = 30;
    arr[1][1] = 40;
    arr[1][2] = 50;
    arr[1][3] = 60;

    arr[2][0] = 70;
    arr[2][1] = 80;
    arr[2][2] = 90;

    // Display
    cout << "Jagged Array:" << endl;

    for (int i = 0; i < rows; i++)
    {
        // Har row ki apni length hai,
        // isliye yahan manually lengths use kar rahe hain.
        
        int size;

        if (i == 0)
            size = 2;
        else if (i == 1)
            size = 4;
        else
            size = 3;

        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    // Memory release
    delete[] arr[0];
    delete[] arr[1];
    delete[] arr[2];

    delete[] arr;

    return 0;
}

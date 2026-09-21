#include <iostream>
using namespace std;

int main()
{
    int arr[] = {170, 45, 75, 90, 802,2,25,66};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Insertion Sort
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;

        // Shift larger elements to the right
        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        // Insert curr at its correct position
        arr[prev + 1] = curr;
        
        cout<<"\nArray after "<<i<<" pass(es)\n";
         for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    }
cout<<"\n";
    // Display sorted array
    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
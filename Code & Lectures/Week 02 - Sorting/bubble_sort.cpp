#include <iostream>
using namespace std;

int main()
{
    int arr[] = {170, 45, 75, 90, 802,2,25,66};
    int n = sizeof(arr)/sizeof(arr[0]);
    
int passes = 0;
int swaps = 0;
   
   cout << "Unsorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout<<"\n";

    // Bubble Sort
    for (int i = 0; i < n - 1; i++)
    
    {
    	passes++;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }

    // Display sorted array
    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
cout<<"\nNo. of Passes: "<<passes;
cout<<"\nNo. of Swaps: "<<swaps;
    
	return 0;
    
}
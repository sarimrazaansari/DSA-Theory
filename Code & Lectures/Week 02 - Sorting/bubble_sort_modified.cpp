#include <iostream>
using namespace std;

int main()
{
    int arr[] = {45, 75, 90, 2, 25, 66, 170, 802};
     int n = sizeof(arr)/sizeof(arr[0]);
     
     int passes = 0;
int swaps = 0;
      
	  cout << "Unsorted Array: ";
      

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout<<"\n";

    for (int i = 0; i < n - 1; i++)
    {
        passes++;
		bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
                swaps++;
            }
        }

        // No swapping means array is already sorted
        if (swapped == false)
            break;
    }

    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }


cout<<"\nNo. of Passes: "<<passes;
cout<<"\nNo. of Swaps: "<<swaps;

    return 0;
}
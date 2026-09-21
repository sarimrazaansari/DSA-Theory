#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    
	
	  
	}
    
    
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 2, 25, 66};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    selectionSort(arr, n);
   
    

    cout << "\nSorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
#include <iostream>
using namespace std;

void shellSort(int arr[], int n)
{
    // Start with a large gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Perform insertion sort with this gap
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;

            // Shift elements that are greater than temp
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
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

    shellSort(arr, n);

    cout << "\nSorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
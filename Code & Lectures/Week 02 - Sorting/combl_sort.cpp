#include <iostream>
using namespace std;

void combSort(int arr[], int n)
{
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped)
    {
        // Reduce gap
        gap = gap / 1.3;

        if (gap < 1)
        {
            gap = 1;
        }

        swapped = false;

        // Compare elements with the current gap
        for (int i = 0; i + gap < n; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;

                swapped = true;
            }
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

    combSort(arr, n);

    cout << "\nSorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
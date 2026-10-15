#include <iostream>
using namespace std;

//pivot ke left side pr smaller element and right pr bigger elements

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; //last
    int i = low - 1;    //index to replace with if find smaller

    //placing pivot in right position
    for (int j = low; j < high; j++) //j<high -> doesnt include pivot to compare 
    {
        if (arr[j] < pivot)
        {
            i++;

            swap(arr[i],arr[j]); //smaller ek side pr
        }
    }

    swap(arr[i+1],arr[high]); //now we r placing pivot to right postion -> just after smaller elements

    return i + 1; //pivot
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int arr[] = {8, 3, 1, 7, 0, 10, 2};

    int n = 7;

    cout << "Before Sorting: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    quickSort(arr, 0, n - 1);

    cout << "\nAfter Sorting: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
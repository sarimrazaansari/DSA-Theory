#include <iostream>
using namespace std;

/*
    102 20
    105 30
    104 40
    101 50
    103 80
*/

void bubbleSort(int arr[][2],int n){
    for(int i=0; i<n-1 ;i++){
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j][1]>arr[j+1][1]){
                swap(arr[i][1],arr[j][1]); // have to swap both 0th and 1st element
                swap(arr[i][0],arr[j][0]);
            }
        }
        
    }
}

void selectionSort(int arr[][2],int n){
    for (int i = 0; i < n-1; i++)
    {
        int minIdx=i;
        for (int j = i+1; j < n ; j++)
        {
            if (arr[minIdx][1]>arr[j][1])
            {
                minIdx=j;
            }
            
        }
        swap(arr[minIdx][1],arr[i][1]);
        swap(arr[minIdx][0],arr[i][0]);
    }
    
}

void insertionSort(int arr[][2], int n) {
    for (int i = 1; i < n; i++) {
        // 1. Store both columns of the current row as the "key"
        int key0 = arr[i][0];
        int key1 = arr[i][1];
        
        int j = i - 1;

        // 2. Shift elements of the sorted segment forward if their 
        // second column is greater than the key's second column
        while (j >= 0 && arr[j][1] > key1) {
            arr[j + 1][0] = arr[j][0];
            arr[j + 1][1] = arr[j][1];
            j = j - 1;
        }
        
        // 3. Insert the key into its correct sorted position
        arr[j + 1][0] = key0;
        arr[j + 1][1] = key1;
    }
}


int main(){
    int arr[][2]={{1,23},{2,12},{3,42}};
    int n=size(arr);
    selectionSort(arr,n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    

}
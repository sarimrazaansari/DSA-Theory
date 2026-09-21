#include "iostream"
using namespace std;

void bubbleSort(int *arr,const int size){
    //Compare two adjacent element. The biggest element will go in right place
    // o(n**2)
    int passes=0,swaps=0;

    for (int i = 0; i < size-1; i++){
        passes++;
        
        for (int j = 0; j < size-i-1; j++){
            if (arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swaps++;
            }
        }
    }
    cout<<"Passes: "<<passes<<endl;
    cout<<"Swaps: "<<swaps<<endl;

}   

void selectionSort(int *arr,const int size){
// Assume first elemnt is alr sort then loop to find actual min index then replace it with assume one

    for (int i = 0; i < size-1; i++)
    {
        int minIndex=i;

        for (int j = i+1; j < size; j++)
        {
            if (arr[minIndex]>arr[j])
            {   //real smallest is found here
                minIndex=j;
            }
            
        }
        //now replace with assume one
        swap(arr[i],arr[minIndex]); 
        
    }
    

}

void insertionSort(int *arr,const int n){

    for(int i=1; i<n;i++){
        int curr=arr[i];
        int prev=i-1;

        while (prev>=0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
    }

}

int main(){
    int arr[] = {170, 45, 75, 90, 802,2,25,66};
    int size=sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr,size);

    cout<<"Soted Array: ";
    for (int i = 0; i < size-1; i++){
        cout<<arr[i]<<" ";
    }
    

}
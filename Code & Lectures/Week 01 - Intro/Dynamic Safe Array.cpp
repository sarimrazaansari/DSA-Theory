#include<iostream>
using namespace std;

class SafeArray{
	
	private:
		int *arr;
		int limit;
		int value;
		
	public:
		SafeArray(int Size)
		{
			arr = new int(Size);
			limit=Size;
			cout << "Enter values to insert" << endl;
			for (int x = 0; x < Size ; x++) 
			{
				cin >> arr[x];
			}
		
		}
		
		void a(int n){
			if(n<0 || n>limit)
			cout<<"out of bound error";
			else 
			{
				
				for(int i=0;i<limit;i++)
					cout << arr[i] << " "<<endl;
				
			}
			
		}
		
		~SafeArray(){delete [] arr;}
	
	
};
int main() {
	int size;
	cout<<"Enter the length of the array";
	cin>>size;
	SafeArray obj(size);
	obj.a(size);
}

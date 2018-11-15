#include <iostream>
using namespace std;
int Binary_Search(int arr[], int n, int key)
{
    int start=0, end=n-1, mid, index;
    while(start<=end){
		mid = (start+end)/2;
		if(arr[mid] == key){
			index = mid;
			break;
		}
		else if(arr[mid]<key) start = mid+1;
		else if(arr[mid]>key) end = mid-1;
	}
	return index;
}
int main()
{
	int arr[100], key, n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	cin>>key;
	n = Binary_Search(arr, n, key);
	cout<<n+1<<endl;
	return 0;
}


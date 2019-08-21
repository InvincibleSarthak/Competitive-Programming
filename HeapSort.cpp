#include<iostream>
using namespace std;
void heapify(int *arr, int n, int i){
	int maxi = i;
	int left = 2*i+1;
	int right = 2*i+2;
	if(left < n && arr[left] > arr[maxi]){
		maxi = left;
	}
	if(right < n && arr[right] > arr[maxi]){
		maxi = right;
	}
	if(maxi != i){
		swap(arr[maxi],arr[i]);
		heapify(arr,n,maxi);
	}
}
void heapsort(int *arr, int n){
	for(int i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
	}
	for(int i=n-1;i>=0;i--){
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}
void print(int *arr, int n){
	for(int i=n-1;i>=0;i--){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	heapsort(arr,n);
	print(arr,n);
}

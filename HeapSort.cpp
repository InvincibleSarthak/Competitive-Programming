#include<iostream>
using namespace std;
void heapify(int *arr, int n, int i){  //finding largest of node and its children and swap the child with its parent if child node is greater
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
	for(int i=n/2-1;i>=0;i--){   //caliing heapify function from n/2 index to 0 th index of array
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
	cin>>n;    //inpur array size
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i]; //input array
	}
	heapsort(arr,n);  //calling heapsort function
	print(arr,n);
}

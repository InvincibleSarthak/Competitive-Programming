#include<iostream>
using namespace std;
void minHeap(int *arr, int n){
	for(int i=0;i<=n/2-1;i++){
		int minimum = i;
		int left = 2*i+1;
		int right = 2*i+2;
		if(left < n && arr[left]<=arr[minimum]){
			minimum = left;
		}
		if(right < n && arr[right]<=arr[minimum]){
			minimum = right;
		}
		if(minimum != i){
			swap(arr[minimum] , arr[i]);
		}	
	}
}
int heapMinimum(int* arr){
	return arr[0];
}
void heapExtractMin(int *arr, int n){
	swap(arr[0],arr[n-1]);
	minHeap(arr,n-1);
	cout<<heapMinimum(arr);
}
void minHeapInsert(int *arr, int n, int val){
	for(int i=0;i<n;i++){
		if(arr[i]==val){
			return;
		}
	}
	arr[n]=val;
	minHeap(arr,n);
}
void decreaseKey(int *arr, int n, int val, int newVal){
	int index;
	for(int i=0;i<n;i++){
		if(arr[i] == val){
			arr[i]=newVal;
			break;
		}
	}
	minHeap(arr,n);
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	minHeap(arr,n);
	cout<<heapMinimum(arr)<<"\n";
	heapExtractMin(arr,n);
	int val;
	cin>>val;
	minHeapInsert(arr,sizeof(arr),val);
	cin>>val;
	int newVal;
	cin>>newVal;
	decreaseKey(arr,sizeof(arr), val, newVal);
} 

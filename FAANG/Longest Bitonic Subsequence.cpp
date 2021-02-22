#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int n, int *arr){
	int left[1001];
	int right[1001];
	left[0] = 1;
	int temp;
	for(int i=1;i<n;i++){
		temp = 1;
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i])	temp = max(temp,left[j]+1);
		}
		left[i] = temp;
	}
	right[n-1] = 1;
	for(int i=n-2;i>=0;i--){
		temp = 1;
		for(int j=i;j<n;j++){
			if(arr[j]<arr[i])	temp = max(temp,right[j]+1);
		}
		right[i] = temp;
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		ans = max(ans,left[i]+right[i]-1);
	}
	return ans;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<<solve(n,arr)<<'\n';
	}
	return 0;
}

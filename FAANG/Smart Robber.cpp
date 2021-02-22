#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)	cin>>arr[i];
		int dp[n];
		dp[0] = arr[0];
		dp[1] = max(arr[1],arr[0]);
		for(int i=2;i<n;i++){
			dp[i] = max(dp[i-2]+arr[i],dp[i-1]);
		}
		cout<<dp[n-1]<<'\n';
	}
	return 0;
}

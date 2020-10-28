#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,x;
	    cin>>n>>x;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int ans = INT_MAX, left = 0, right = 0;
	    int sum = 0;
	    while(left<n && right<n){
	        sum += arr[right];
	        if(sum<=x){
	            right++;
	        }
	        else{
	            ans = min(ans,right-left+1);
	            sum -= (arr[left]+arr[right]);
	            left++;
	        }
	    }
	    cout<<ans<<'\n'; 
	}
	return 0;
}

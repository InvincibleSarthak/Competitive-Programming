#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    unordered_set<int>s;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        s.insert(arr[i]);
	    }
	    int ans = 0;
	    for(int i=0;i<n;i++){
	        if(s.find(arr[i]-1) == s.end()){
	            int j = arr[i];
	            while(s.find(j) != s.end()) j++;
	        
	            ans = max(ans,j-arr[i]);
	        }
	    }
	    cout<<ans<<'\n';
	}
	return 0;
}

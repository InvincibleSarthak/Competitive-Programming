#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    int sum[n];
	    map<int,int>m;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    string ans = "No";
	    sum[0] = arr[0];
	    for(int i=1;i<n;i++){
	        sum[i] = sum[i-1] + arr[i];
	    }
	    for(int i=0;i<n;i++){
	        if(sum[i] == 0 || (m.find(sum[i]) != m.end())){
	            ans = "Yes";
	            break;
	        }
	        m[sum[i]] = 1;
	    }
	    cout<<ans<<'\n';
	}
	return 0;
}

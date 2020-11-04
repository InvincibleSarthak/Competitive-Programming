#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int x,y,z;
	    cin>>x>>y>>z;
	    int dp[n+1]={0};
	    map<int,bool>visited;
	    for(int i=0;i<=n;i++){
	        visited[i] = false;
	    }
	    visited[0] = true;
	    for(int i=1;i<=n;i++){
	        if(i>=x && visited[i-x]){
	            visited[i] = true;
	            dp[i] = max(dp[i],dp[i-x]+1);
	        }
	        if(i>=y && visited[i-y]){
	            visited[i] = true;
	            dp[i] = max(dp[i],dp[i-y]+1);
	        }
	        if(i>=z && visited[i-z]){
	            visited[i] = true;
	            dp[i] = max(dp[i],dp[i-z]+1);
	        }
	    }
	    cout<<dp[n]<<'\n';
	}
	return 0;
}

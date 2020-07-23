#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<pair<int,int>> &vec, int n, int w){
    int dp[n][w+1];
    for(int i=0;i<n;i++){
        dp[i][0] = 0;
    }
    for(int j=1;j<=w;j++){
        dp[0][j] = 0;
        if(j>=vec[0].first) dp[0][j] = vec[0].second;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=w;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=vec[i].first) dp[i][j] = max(vec[i].second + dp[i-1][j-vec[i].first], dp[i][j]);
        }
    }
    return dp[n-1][w];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,w;
        cin>>n>>w;
        int val[n], wt[n];
        for(int i=0;i<n;i++){
            cin>>val[i];
        }
        for(int i=0;i<n;i++){
            cin>>wt[i];
        }
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back(make_pair(wt[i],val[i]));
        }
        sort(vec.begin(),vec.end());
        cout<<solve(vec,n,w)<<'\n';
    }
}

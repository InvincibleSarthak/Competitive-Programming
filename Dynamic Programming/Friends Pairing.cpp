#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[1000];
int solve(int i){
    if(i==1){
        return 1;
    }
    if(i==0){
        return 1;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    dp[i] = solve(i-1) + solve(i-2)*(i-1);
    return dp[i];
}
int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    int ans = solve(n);
    cout<<(ans);
}

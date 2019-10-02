//Player1 and Player2 are equally smart and are allowed to pick the number either from start or from the end. Our aim is to print the
//maximum possible win difference between them.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[1000];
int dp[1000][1000];
int solve(int i, int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
//     As the next player will try to minimize our winning chances, we'll take min for next chances.
    int q1 = arr[i]+min(solve(i+2,j) , solve(i+1,j-1));
    int q2 = arr[j]+min(solve(i,j-2) , solve(i+1,j-1));
    dp[i][j] = max(q1,q2);
    return dp[i][j];
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    int sum = 0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    int ans = solve(0,n-1);
    cout<<2*ans - sum<<" ";
}

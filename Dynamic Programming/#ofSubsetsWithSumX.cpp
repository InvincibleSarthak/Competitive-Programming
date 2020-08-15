#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>vec;
    int temp;
    int sum;
    for(int i=0;i<n;i++){
        cin>>temp;
        vec.push_back(temp);
    }
    cin>>sum;
    int dp[n+1][sum+1];
    for(int j=0;j<=sum;j++){
        dp[0][j] = 0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(vec[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-vec[i-1]];
            }
            else    dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][sum];
}

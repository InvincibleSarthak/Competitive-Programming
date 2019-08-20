//To print the number of ways to cover desired distance

#include<iostream>
using namespace std;
int solve(int n){
    int dp[n];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    int ans = solve(n);
    cout<<ans;
}

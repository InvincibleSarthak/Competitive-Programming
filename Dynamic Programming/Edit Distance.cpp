//Program to print the minimum number of changes required to print the desired string.
//Insertion, Deletion and Replacement of a char is allowed. 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(char *inp, char *out){
    int dp[101][101];
    int m = strlen(inp);
    int n = strlen(out);
    dp[0][0] = 0;
    for(int i=1;i<=m;i++){
        dp[i][0] = dp[i-1][0] + 1;
    }
    for(int j=1;j<=n;j++){
        dp[0][j] = dp[0][j-1] + 1;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(inp[i] == out[j]){
                dp[i][j] = min(dp[i-1][j] , min (dp[i-1][j-1] , dp[i][j-1]));
                continue;
            }
            else{
                int q1 = 1+dp[i-1][j]; // insertion
                int q2 = 1+dp[i-1][j-1]; // replacement
                int q3 = 1+dp[i][j-1];  // deletion
                dp[i][j] = min(q1,min(q2,q3));
            }
        }
    }
    return dp[m][n];
}
int main(){
    char inp[100], out[100];
    cin>>inp>>out;
    int ans = solve(inp,out);
    cout<<ans<<"\n";
}

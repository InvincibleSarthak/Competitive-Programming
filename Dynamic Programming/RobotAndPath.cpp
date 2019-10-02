// To print the number of paths to reach m,n tile from 1,1 and only eastward and southward movement is allowed.

#include<iostream>
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int dp[1000][1000];
int solve(int m, int n){
//     Base case if starting position is blocked
    if(dp[0][0] == -1){
        return 0;
    }
//     If end position is blocked
    if(dp[m-1][n-1] == -1){
        return 0;
    }
    for(int i=0;i<m;i++){
        if(dp[i][0] == -1){
            break;
        }
        dp[i][0]=1;
    }
    for(int j=0;j<n;j++){
        if(dp[0][j] == -1){
            break;
        }
        dp[0][j]=1;
    }
    for(int j=1;j<n;j++){
        for(int i=1;i<m;i++){
            if(dp[i][j] == -1){
                continue;
            }
            else{
                if(dp[i][j-1] == -1){
                    dp[i][j] = (dp[i-1][j])%MOD;
                }
                if(dp[i-1][j] == -1){
                    dp[i][j] = (dp[i][j-1])%MOD;
                }
                else if(dp[i-1][j] != -1 && dp[i][j-1] != -1){
                    dp[i][j] = ((dp[i-1][j])%MOD + (dp[i][j-1])%MOD)%MOD;
                }
            }
        }
    }
    return dp[m-1][n-1];
}
int main(){
    memset(dp,0,sizeof(dp));
    int m,n,p;
    cin>>m>>n>>p;
    int x,y;
    while(p--){
        cin>>x>>y;
        dp[x-1][y-1]=-1;
    }
    cout<<solve(m,n)<<endl;
}

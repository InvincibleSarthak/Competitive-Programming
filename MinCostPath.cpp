//To find the minimum cost to travel from 1,1 to x,y.
//The 3*3 matrix entered contains the cost values for different paths.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[3][3];
int dp[3][3];

int solve(int x, int y){
    if(x==0 && y==0)    return arr[0][0];
    if(dp[x][y] != -1)  return dp[x][y];
    else if(x==0 && y!=0)   dp[x][y] = solve(0,y-1) + arr[x][y];
    else if(y==0 && x!=0)   dp[x][y] = solve(x-1,0) + arr[x][y];
    else{
        dp[x][y] = min(solve(x-1,y-1), min(solve(x-1,y), solve(x,y-1))) + arr[x][y];
    }
    return dp[x][y];
}

int main(){
    memset(dp,-1,sizeof(dp));
    for( int i=0; i<3; i++ ){
        for( int j=0; j<3; j++ ){
            cin>>arr[i][j];
        }
    }
    int x,y;
    cin>>x>>y;
    cout<<solve(x-1,y-1);
}

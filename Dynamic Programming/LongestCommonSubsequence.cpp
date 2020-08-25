//Given: Two strings 
//To print the longest common subsequence

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int m = s1.size();
    int n = s2.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=n;j++){
        dp[0][j] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    int a=m,b=n;
    string ans;
    while(a>0 || b>0){
        if(s1[a-1] == s2[b-1]){
            ans += s1[a-1];
            a--;
            b--;
        }
        else if(dp[a-1][b] > dp[a][b-1]){
            a--;
        }
        else{
            b--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}

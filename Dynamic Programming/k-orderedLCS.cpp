//String Problem Again - HackerEarth

#include<iostream>
using namespace std;
#define ll long long int
string s,t;
ll n,m;
ll dp[2000][2000][5];
ll solve(ll i, ll j, ll k){
    if(i==n || j==m){
        return 0;
    }
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    ll res = 0;
    if(s[i] == t[j]){
        res = 1 + solve(i+1,j+1,k);
    }
    else{
        if(k>0){
            res = 1 + solve(i+1,j+1,k-1);
        }
        res = max(res,solve(i+1,j,k));
        res = max(res,solve(i,j+1,k));
    }
    return dp[i][j][k] = res;
}
int main(){
    cin>>s>>t;
    n=s.length();
    m=t.length();
    ll k;
    cin>>k;
    ll ans = solve(0,0,k);
    cout<<ans<<endl;
}

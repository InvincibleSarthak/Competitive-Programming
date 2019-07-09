#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
//#define INT_MAX 100002 
using namespace std;
ll dp[100000];
ll ar[100000];

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map< ll, ll > mark;
        ll pre=0;
        ll cnt= 0;
        ll ans= INT_MIN;
        for(ll i=1;i<=n;i++){
            cin>>ar[i];
            dp[i]=max(dp[i-1]+ar[i],ar[i]);
            ans = max(ans,dp[i]);
        }
        mark[0]++;
        for(ll i=1;i<=n;i++){
            pre += ar[i];
            cnt += mark[pre-ans];
            mark[pre]++;
        }
        cout<<ans<<" "<<cnt<<" "<<endl;
    }
}


Input:
2
3
-1 -1 -1
4
2 0 -2 2

Output:
-1 3 
2 4 

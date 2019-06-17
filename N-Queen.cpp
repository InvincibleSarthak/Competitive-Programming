//To solve N-Queen Problem using backtracking with help of bitset

#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bitset<30> col,d1,d2;
void solve(ll r, ll n, ll &ans){
    if(r==n){
        ans++;
        return;
    }
    for(ll c=0;c<n;c++){
        if(!col[c] && !d1[r-c+n-1] && !d2[r+c]){
            col[c]=d1[r-c+n-1]=d2[r+c]=1;
            solve(r+1,n,ans);
            col[c]=d1[r-c+n-1]=d2[r+c]=0;
        }
    }
}
int main(){
    ll n,ans=0;
    cin>>n;
    solve(0,n,ans);
    cout<<ans<<endl;
}

/*To print Yes if sum of any of the subsequence is equal to the desired value else No
Imp: subsequences are not always contigous. SubArrays are always contigous.*/
#include<iostream>
#define ll long long int
#include<bits/stdc++.h>
using namespace std;
int main(){
    ll t,n,m,arr[1000];
    cin>>t;
    while(t--){
        int o=0;
        cin>>n>>m;
        for(ll j=0;j<n;j++){
            cin>>arr[j];
        }
        for(ll j=1;j<=((1<<n)-1);j++){
            ll k=0,l=j,sum=0;
            while(l>0){
                if((l&1)==1){
                    sum+=arr[k];    
                }
                l=l>>1;
                k++;
            }
            if(sum==m){
                o++;
            }
        }    
        if(o>0){
            cout<<"Yes";
        }
        else{
            cout<<"No";
        }
    }
}

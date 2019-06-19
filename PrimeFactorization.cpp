#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
const ll N = 100000002;
using namespace std;
ll n;
vector<ll>vec;
ll arr[N];
void sieve(){
    arr[2]=1;
    arr[0]=arr[1]=0;
    for(ll i=3;i<=n;i+=2){
        arr[i]=1;
        arr[i+1]=0;
    }
    for(ll i=3;i<=n;i+=2){
        if(arr[i]==1){
            for(ll j=i*i;j<=n;j+=2*i){
                arr[j]=0;
            }
        }
    }
    return;
}
void primeFactor(ll a){
    for(ll i=2;i<=n;i++){
        if(arr[i]==1){
            while(n%i==0){
                n=n/i;
                vec.push_back(i);
            }
        }
    }
}
int main(){
    cin>>n;
    sieve();
    primeFactor(n);
    for(auto it:vec){
        cout<<it<<' ';
    }
}

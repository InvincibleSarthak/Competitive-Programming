//Basic program to print all the prime numbers till n.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=100000002;
ll arr[N];
void primeCheck(ll n){
    arr[0]=arr[1]=0;
    arr[2]=1;
    for(ll i=3;i<=n;i+=2){ //initially marking every number as prime
        arr[i]=1;
        arr[i+1]=0;
    }
    for(ll i=3;i<=n;i+=2){  
        if(arr[i]==1){
            for(ll j=i*i;j<=n;j+=2*i){  //marking multiples of number j as non prime
                arr[j]=0;
            }
        }
    }
    return;
}
int main(){
    ll n;
    cin>>n;
    primeCheck(n);
    for(ll i=2;i<=n;i++){
        if(arr[i]==1)
            cout<<i<<' ';
    }
    return 0;
}

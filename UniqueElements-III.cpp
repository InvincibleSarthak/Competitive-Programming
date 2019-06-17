//To print the unique element from an array where all the other elements are present three times

#include<iostream>
using namespace std;
#define ll long long int
const int N=1000002;
int arr[N];
int main(){
    ll a,res[64]={0};
    cin>>a;
    for(ll i=0;i<a;i++){
        cin>>arr[i];
    }
    for(ll i=0;i<a;i++){
        ll j=0;
        ll num=arr[i];
        while(num>0){
            res[j]+=(num&1);
            num=num>>1;
            j++;
        }
    }
    ll unnum=0;
    for(ll i=0;i<a;i++){
        res[i]%=3;
        unnum+=(res[i]<<i);
    }
    cout<<unnum<<endl;
}

//To print all the prime numbers present between l to r with time complexity of order O(nloglogn)



#include<iostream>
#include<math.h>
using namespace std;
#define ll long long int
const ll N=100000002;
ll arr1[N],arr2[N];
ll l,r,val;
void sieve(ll a){
    arr1[2]=1;
    arr1[0]=arr1[1]=0;
    val=sqrt(a);
    for(ll i=3;i<=val;i+=2){
        arr1[i]=1;
        arr1[i+1]=0;
    }
}
void solve(ll a, ll b){
    for(ll i=0;i<=b-a;i++){
        arr2[i]=a+i;
    }
    for(ll i=2;i<=val;i++){
        if(arr1[i]==1){
            for(ll j=0;j<=b-a;j++){
                if(arr2[j]%i==0){
                    arr2[j]=0;
                }
            }
        }
    }
    for(ll j=0;j<=b-a;j++){
        if(arr2[j]!=0){
            cout<<arr2[j]<<' ';
        }
    }
}
int main(){
    cin>>l>>r;
    sieve(r);
    solve(l,r);
}

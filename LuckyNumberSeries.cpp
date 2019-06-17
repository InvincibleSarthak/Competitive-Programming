//CodeForces 535-B
//To print the index of lucky number which is of order 10^9


#include <iostream>
using namespace std;
#define ll long long int
const int N=1000002;
ll arr[N];
int main(){
    ll a;
    cin>>a;
    ll temp=a,j=0,sum=0;
    while(temp>0){
        if(temp%10==7){
            sum+=(1<<j);
        }
        j++;
        temp/=10;
    }
    for(ll i=j-1;i>=0;i--){
        sum+=(1<<i);
    }
    cout<<sum<<endl;
}

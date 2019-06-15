//We have to find two unique elements present in our array

#include<iostream>
#define ll long long int
using namespace std;
const ll N=1000002;
ll arr[N];
int main(){
    ll n,res=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        res=res^arr[i];
    }
    ll temp=res,i=0;
    while(temp>0){
        if(temp&1){
            break;
        }
        i++;
        temp=temp>>1;
    }
    ll firstNo=0,secondNo=0;
    for(ll j=0;j<n;j++){
        if(arr[j]&(1<<i)){
            firstNo=firstNo^arr[j];
        }
    }
    secondNo=res^firstNo;
    cout<<"First Unique Number is: "<<firstNo<<endl;
    cout<<"Second Unique Number is: "<<secondNo<<endl;
}

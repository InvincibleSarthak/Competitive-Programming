//If we use power function or any other method : Time Complexity= O(n)
//In this method we have time complexity of O(log n) where n is the power


#include <iostream>
using namespace std;
#define ll long long int
ll power(ll a, ll n){
    //base case
    if (n==0){
        return 1;
    }
    //recurssive case
    ll innerAns=power(a,n/2);
    innerAns *= innerAns;

    if(n&1){//runs only if n is odd
        innerAns *= a;
    }
    return innerAns;
}
int main(){
    ll n,a,ans;
    cin>>a>>n;
    ans=power(a,n);
    cout<<ans<<endl;
}

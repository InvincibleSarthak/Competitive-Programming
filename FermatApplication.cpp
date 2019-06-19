//Application of Fermat's little Theorem and Fast exponentiation
//Lights New Car Problem: Price is A initially but becomes A times every ith day. To find the price at i th day.


#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll mod=1000000007;
ll stringToInt(string a, ll m){
    ll res=0;
    for(ll i=0;i<a.size();i++){
        res = (res*10)%m + (a[i]-'0');
        res %= m;
    }
    return res;
}
ll power(ll a, ll b, ll m){
    if(b==0){
        return 1;
    }
    ll z=power(a,b/2,m);
    z %= m;
    z=(z*z)%m;
    if(b&1){
        return (z*a)%m;
    }
    return z;
}
int main(){
    ll t;
    string a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;

        ll x=stringToInt(a,mod);
        ll y=stringToInt(b,mod-1);

        ll ans = power(x,y,mod);
        cout<<ans<<endl;
    }
}

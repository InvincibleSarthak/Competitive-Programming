//To print the value of x and y in ax+by=GCD(a,b)

#include<iostream>
#define ll long long int
using namespace std;
ll x,y,GCD;
void extended_gcd(ll a, ll b){
    if(b==0){
        x=1;
        y=0;
        GCD=a;
        return;
    }
    extended_gcd(b,a%b);
    ll cx=y;
    ll cy=(x-(a/b)*y);
    x=cx;
    y=cy;
}
int main(){
    ll a,b;
    cin>>a>>b;
    extended_gcd(a,b);
    cout<<a<<"*"<<x<<"+"<<b<<"*"<<y<<" = "<<GCD;
}

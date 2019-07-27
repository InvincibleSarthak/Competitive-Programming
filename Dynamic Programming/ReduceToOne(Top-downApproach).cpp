//This approach involves memoization 

#include<iostream>
#include<algorithm>
const int inf= (int)1e9;
using namespace std;
int memo[1000];
int reduce(int n){
    if(n==1) return 0;
    int q1=inf,q2=inf,q3=inf;
    if(memo[n] != -1) return memo[n];
    if(n%3==0) q1=1+reduce(n/3);
    if(n%2==0) q2=1+reduce(n/2);
    q3 = 1+reduce(n-1);
    memo[n]=min(q1,min(q2,q3));
    return memo[n];
}
int main(){
    int n;
    cin>>n;
    fill(memo,memo+n+1,-1);
    int ans = reduce(n);
    cout<<ans<<endl;
}

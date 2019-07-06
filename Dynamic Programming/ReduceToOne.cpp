//To reduce the number to one in the minimum number of operations.



#include<iostream>
using namespace std;
int dp[10000];
const int inf = 100000000;
int reduce (int n){
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i=4;i<=n;i++){
        int q1=inf;
        int q2=inf;
        int q3=inf;
        if(i%3==0) q1= 1 + dp[i/3];
        if (i%2==0) q2= 1 + dp[i/2];
        q3 = 1 + dp[i-1];
        dp[i]=min(q1,min(q2,q3));
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<reduce(n);
}

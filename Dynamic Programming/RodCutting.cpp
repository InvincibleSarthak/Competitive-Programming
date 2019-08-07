//1-D Dynamic Programming Problem
//It returns the max profit made by the person by cutting the rod in any way possible.


#include<iostream>
using namespace std;
int price[1000];
int maxProfit(int arr[], int length){
    if(length == 0) return 0;
    int dp[length]={};
    for(int i=1;i<=length;i++){
        int best=0;
        for(int cut=1;cut<=i;cut++ ){
            best = max(best,arr[cut]+dp[length-cut]);
        }
        dp[i]=best;
    }
    return dp[length];
}
int main(){
    int length;
    cin>>length;
    for(int i=1;i<=length;i++){
        cin>>price[i];
    }
    int ans = maxProfit(price,length);
    cout<<ans<<" ";
}

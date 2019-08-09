//To print the longest increasing subsequence in the given array

#include<iostream>
using namespace std;
int lis(int arr[], int n){
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=1;
    }
    int best = -1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<=arr[i]){
                int count = 1+dp[j];
                dp[i]=max(dp[i],count);
            }
        }
        best = max(best,dp[i]);
    }
    return best;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<lis(arr,n);
}

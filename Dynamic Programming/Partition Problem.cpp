// To check whether it is possible to divide the given set into two equal subsets. Equal means their sum must be same.

#include<iostream>
using namespace std;
bool solve(int *arr, int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    if(sum%2 != 0){
        return false; 
    }
    else{
        bool dp[n+1][(sum/2)+1];
        dp[0][0] = true;
        for(int i=0;i<=(sum/2);i++){
            dp[0][i] = false;
        }
        for(int i=0;i<=n;i++){
            dp[i][0] = true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=(sum/2);j++){
                dp[i][j] = dp[i-1][j];
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
                }
            }
        }
        return dp[n][sum/2];
    }
    
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool ans = solve(arr,n);
    if(ans){
        cout<<"Division is possible!";
    }
    else{
        cout<<"Division not possible!";
    }
}

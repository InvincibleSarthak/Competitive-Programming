#include<iostream>
using namespace std;
int arr[10];
int dp[20][20];
int solve(int n, int sum){
    // mark 1 at all entries with sum=0 
    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }
    // if no element is present in the array, the sum can never be greater than 0, mark 0
    for(int i=1;i<sum;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            
            //if current sum 'j' is less than current element 'arr[i-1]' then we can say that if there was a subset previously mark 1 
            //else mark 0.
            if(j<arr[i-1])  dp[i][j] = dp[i-1][j];
            
            //if current sum  >= current element then we can say that if there was a subset previously or if we subtract current element 
            //from the current sum, we go to a subset , then mark 1
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][sum];
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    if(solve(n,sum))  cout<<"Yes";
    else  cout<<"No";
    return 0;
}

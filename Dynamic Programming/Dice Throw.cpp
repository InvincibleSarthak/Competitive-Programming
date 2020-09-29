//Given N dice each with M faces, numbered from 1 to M, find the number of ways to get sum X. X is the summation of values on each face when all the dice are thrown.


class Solution {
  public:
    long long noOfWays(int m , int n , int sum) {
        long long int dp[n+1][sum+1];
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int i=0;i<=sum;i++){
            dp[0][i] = 0;
        }
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                dp[i][j] = 0;
                if(j>=m){
                    for(int k=1;k<=m;k++){
                        dp[i][j] += dp[i-1][j-k];
                    }
                }
                else{
                    for(int k=1;k<=j;k++){
                        dp[i][j] += dp[i-1][j-k];
                    }
                }
                // cout<<dp[i][j]<<' ';
            }
            // cout<<'\n';
        }
        return dp[n][sum];
    }
};

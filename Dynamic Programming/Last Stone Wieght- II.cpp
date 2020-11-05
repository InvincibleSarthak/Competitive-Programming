class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += stones[i];
        }
        int k = (sum>>1);
        int dp[n+1][k+1];
        
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int j=0;j<=k;j++){
            dp[0][j] = 0;
        }
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(j>=stones[i-1]){
                    dp[i][j] = dp[i-1][j-stones[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        int s;
        for(int i=k;i>=0;i--){
            if(dp[n][i] == 1){
                s = i;
                cout<<s<<' ';
                break;
            }      
        }
        
        return (sum-(2*s));
    }
};

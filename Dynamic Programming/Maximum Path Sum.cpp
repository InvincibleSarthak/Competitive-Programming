class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int dp[N][N];
        int ans = INT_MIN;
        
        if(N == 0)  return 0;
        if(N == 1)  return Matrix[0][0];
        
        for(int i=0;i<N;i++){
            dp[0][i] = Matrix[0][i];
        }
        
        for(int i=1;i<N;i++){
            for(int j=0;j<N;j++){
                int left = INT_MIN, right = INT_MIN;
                if(j>=1){
                    left = dp[i-1][j-1];
                }
                if(j<N-1){
                    right = dp[i-1][j+1];
                }
                    dp[i][j] = max({left,right,dp[i-1][j]}) + Matrix[i][j];
            }
        }
        
        for(int i=0;i<N;i++){
            ans = max(ans,dp[N-1][i]);
        }
        return ans;
    }
};

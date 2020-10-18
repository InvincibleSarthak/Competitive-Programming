class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int dp[n][m];
        bool ob = false;
        for(int i=0;i<n;i++){
            if(obstacleGrid[i][0] == 1) ob = true;
            if(!ob) dp[i][0] = 1;
            else    dp[i][0] = 0;
        }
        ob = false;
        for(int j=0;j<m;j++){
            if(obstacleGrid[0][j] == 1) ob = true;
            if(!ob) dp[0][j] = 1;
            else    dp[0][j] = 0;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};

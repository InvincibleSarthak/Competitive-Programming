class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n==0)    return 0;
        int m = matrix[0].size();
        int row[n][m], col[n][m],dp[n][m];
        int count = 1;
        for(int i=0;i<n;i++){
            row[i][0] = matrix[i][0]-'0';
            for(int j=1;j<m;j++){
                if((matrix[i][j] == matrix[i][j-1]) && (matrix[i][j] == '1')){
                    row[i][j] = row[i][j-1] + 1;
                }
                else if((matrix[i][j] != matrix[i][j-1]) && (matrix[i][j] == '1')){
                    row[i][j] = 1;
                }
                else    row[i][j] = 0;
            }
        }
        
        for(int j=0;j<m;j++){
            col[0][j] = matrix[0][j] - '0';
            for(int i=1;i<n;i++){
                if((matrix[i][j] == matrix[i-1][j]) && (matrix[i][j] == '1')){
                    col[i][j] = col[i-1][j] + 1;
                }
                else if((matrix[i][j] != matrix[i-1][j]) && (matrix[i][j] == '1')){
                    col[i][j] = 1;
                }
                else    col[i][j] = 0;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            dp[i][0] = matrix[i][0]-'0';
            ans = max(ans,dp[i][0]);
        }
        for(int j=0;j<m;j++){
            dp[0][j] = matrix[0][j]-'0';
            ans = max(ans,dp[0][j]);
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j] == '0')   dp[i][j] = 0;
                else    dp[i][j] = min({dp[i-1][j-1],row[i][j-1],col[i-1][j]}) + 1;
                ans = max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};

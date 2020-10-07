class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n==0)    return 0;
        int m = matrix[0].size();
        int row[n][m], col[n][m];
        vector<vector<pair<int,int>>>dp(n,vector<pair<int,int>>(m,{0,0}));
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
        
        //row,col
        int ans = 0;
        for(int j=0;j<m;j++){
            dp[0][j] = {row[0][j],matrix[0][j]-'0'};
            ans = max(ans,row[0][j]);
        }
        for(int i=0;i<n;i++){
            dp[i][0] = {matrix[i][0]-'0',col[i][0]};
            ans = max(ans,col[i][0]);
        }
        int r,c,temp;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j] == '1'){
                    r = min(row[i][j-1],dp[i-1][j-1].first);
                    c = min(col[i-1][j],dp[i-1][j-1].second);
                    temp = max(row[i][j],col[i][j]);
                    if(temp > (r+1)*(c+1)){
                        if(temp == col[i][j])   dp[i][j] = {1,col[i][j]};
                        else    dp[i][j] = {row[i][j],1}; 
                    }
                    else    dp[i][j] = {r+1,c+1};
                    ans = max(ans,dp[i][j].first * dp[i][j].second);
                }
                else    dp[i][j] = {0,0};
            }
        }
        return ans;
    }
};

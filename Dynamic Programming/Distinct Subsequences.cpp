class Solution {
public:
    
    int numDistinct(string s, string t, int n, int m, vector<vector<int>>&dp){
        if(m == 0)  return dp[n][m] = 1;
        if(n<m)   return dp[n][m] = 0;
        
        if(dp[n][m] != -1){
            return dp[n][m]; 
        }
        int count = 0;
        if(s[n-1] == t[m-1]){
            count += numDistinct(s,t,n-1,m-1,dp);
            count += numDistinct(s,t,n-1,m,dp);
        }
        else{
            count += numDistinct(s,t,n-1,m,dp);
        }
        return dp[n][m] = count;
    }
    
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans = numDistinct(s,t,n,m,dp);
        
        return ans;
    }
};

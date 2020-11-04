class Solution{
public:
    int longestSubsequence(int n, int A[])
    {
        int dp[n];
        int ans = INT_MIN;
        for(int i=0;i<n;i++)    dp[i] = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if((A[j] == A[i]-1) || (A[j] == A[i]+1))  dp[i] = max(dp[j]+1,dp[i]);
            }
            ans = max(ans,dp[i]);
        }
        return ans == INT_MIN ? 1 : ans;
    }
};

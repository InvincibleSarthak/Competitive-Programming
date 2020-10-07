class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        int n = envelopes.size();
        int ans = 1;
        if(n == 0)  return 0;
        int dp[n];mn
        for(int i=0;i<n;i++){
            dp[i] = 1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])  dp[i] = max(dp[i],dp[j]+1);
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};

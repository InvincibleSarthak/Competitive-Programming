class Solution {
public:
    
    int solve(int i, int j, vector<vector<int>>&dp, vector<int>&nums){
        
        if(i==j){
            dp[i][j] = nums[i];
            return dp[i][j];
        }
        if(j-i+1 == 2){
            dp[i][j] = max(nums[i],nums[j]);
            return dp[i][j];
        }
        if(dp[i][j] != -1)  return dp[i][j];
        dp[i][j] = max(min(solve(i+2,j,dp,nums),solve(i+1,j-1,dp,nums)) + nums[i], min(solve(i+1,j-1,dp,nums),solve(i,j-2,dp,nums)) + nums[j]);
        
        return dp[i][j];
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans = solve(0,n-1,dp,nums);
        return 2*ans>=sum ? true : false;
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, end = 0, n = nums.size();
        int sum = 0;
        int count = 0;
        int ans = INT_MAX;
        while(end < n){
            sum += nums[end];
            while(sum>=s){
                count = end - start + 1;
                ans = min(ans,count);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        if(ans == INT_MAX)  return 0;
        return ans;
    }
};

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0)    return 0;
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        int f;
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int temp = nums[i]+nums[j]+nums[k];
                if(temp == target){
                    ans = 0;
                    f = target;
                    j++;
                    k--;
                }
                else if(temp > target){
                    ans = min(ans,temp-target);
                    if(temp-target == ans)  f = temp;
                    k--;
                }
                else{
                    ans = min(ans,target-temp);
                    if(target-temp == ans)  f = temp;
                    j++;
                }
            }
        }
        return f;
    }
};

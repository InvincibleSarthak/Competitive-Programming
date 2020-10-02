class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans=0;
        int n = nums.size();
        if(n==0)    return 0;
        if(n==1)    return 1;
        int left = 0;
        for(int right=1;right<n;right++){
            if(nums[right] != nums[left]){
                left++;
                nums[left] = nums[right];
            }
        }
        return left+1;
    }
};

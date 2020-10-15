// From the right side, search for the first i, such that nums[i] < nums[i+1]. Then on the right of i, search for a number which is just greater than i, let's call it j.
//Now swap nums[i] and nums[j]. Now, sort the remaining right side of the ith element. This will give us the next permutation greater than the given number.


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        while(i>=0 && (nums[i+1] <= nums[i])){
            i--;
        }
        if(i>=0){
            int j = i+1;
            while(j<n && (nums[j]>nums[i])){
                j++;
            }
            j -= 1;
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
        }
        else    reverse(nums.begin(),nums.end());
    }
};

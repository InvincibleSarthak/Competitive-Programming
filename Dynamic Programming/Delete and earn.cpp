class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int>m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(m.find(nums[i]) == m.end())  m[nums[i]]=0;
            m[nums[i]]++;
        }
        int p = 0;
        int ab = 0;
        int ans=0;
        for(auto it: m){
            if(m.find(it.first-1) != m.end()){
                p = m[it.first]*it.first + ab;
                ab = ans;
            }
            else{
                p = m[it.first]*it.first + ans;
                ab = ans;
            }
            ans = max(p,ab);
        }
        return ans;
    }
};

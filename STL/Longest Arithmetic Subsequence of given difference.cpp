class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        unordered_map<int, int> mp;
        int res = 0;
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]] = max(mp[arr[i]], mp[arr[i]-d]+1);    
            res = max(res, mp[arr[i]]);
            cout<<mp[arr[i]]<<' '<<arr[i]<<' ';
        }
        return res;
    }
};

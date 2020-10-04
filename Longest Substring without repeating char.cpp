class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        map<char,int>m;
        int ans = 0, i = 0, j = 0;
        for(int j=0,i=0;j<n;j++){
            if(m.find(s[j]) != m.end()){
                i = max(m[s[j]],i);
            }
            ans = max(ans,j-i+1);
            m[s[j]] = j+1;
        }
        return ans;
    }
};

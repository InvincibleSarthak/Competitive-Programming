class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 0)    return "";
        if(n == 1) return s;
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }
        int mx = INT_MIN,start=-1;
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                start = i;
                mx = 2;
            }
        }
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j = i+k-1;
                if(dp[i+1][j-1] == 1 && s[i] == s[j]){
                    dp[i][j] = 1;
                    if(mx < j-i+1){
                        mx = (j-i+1);
                        start = i;
                    }
                }
            }
        }
        string ans = "";
        if(start == -1){
            ans += s[0];
            return ans;
        }
        for(int i=start;i<start+mx;i++){
            ans += s[i];
        }
        return ans;
    }
};

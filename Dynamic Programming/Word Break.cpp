class Solution {
public:
    bool check(string s, map<string,int>&m){
        if(m.find(s) != m.end())    return true;
        else    return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,int>m;
        for(auto it: wordDict){
            m[it] = 1;
        }
        int n = s.length();
        if(n == 0)  return true;
        bool dp[n+1];
        memset(dp,false,sizeof(dp));
        for(int i=1;i<=n;i++){
            if(dp[i] == false && check(s.substr(0,i),m))  dp[i] = true;
            
            if(dp[i] == true){
                if(i == n)  return true;
                for(int j=i+1;j<=n;j++){
                    if(dp[j] == false && check(s.substr(i,j-i),m))  dp[j] = true;
                    if(j == n && dp[j] == true) return true;
                }
            }
        }
        return false;
    }
};

//To print the longest palindromic substring in the given string
/*
Concept: str[i....j] is palindromic if str[i+1.....j-1] is palindromic and str[i] == str[j].
*/


string Solution::longestPalindrome(string A) {
    int n = A.length();
    bool dp[n][n];
    int maxLength;
    int start = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = 0;
        }
    }
    //every string of length = 1 is palindromic 
    for(int i=0; i<n; i++){
        dp[i][i] = true;
        maxLength = 1;
    }
    //every string of length = 2
    for(int i=0;i<n-1;i++){
        if(A[i] == A[i+1]){
            dp[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }
    //strings of length = k
    for(int k=3;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            int j=i+k-1;
            if(dp[i+1][j-1] && A[i] == A[j]){
                dp[i][j] = true;
                if(k>maxLength){
                    maxLength = k;
                    start = i;
                }
            }
        }
    }
    string ans ="";
    for(int i = start;i<=start+maxLength-1;i++){
        ans += A[i];
    }
    return ans;
}

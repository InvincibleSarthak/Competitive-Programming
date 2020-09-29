class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int start = 0,end=0;
        int n = A.size();
        int ans = INT_MIN;
        while(end<n){
            if(A[end] == 0) K--;
            while(K<0){
                if(A[start] == 0)   K++;
                start++;
            }
            ans = max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};

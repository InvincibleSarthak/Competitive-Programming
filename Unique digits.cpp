
//Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.





class Solution {
public:
    int solve(int n){
        if(n == 1)  return 10;
        int temp = 9, ans=9;
        for(int i=1;i<n;i++){
            ans *= temp;
            temp--;
        }
        return ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans += solve(i);
        }
        return ans == 0? 1 : ans;
    }
};

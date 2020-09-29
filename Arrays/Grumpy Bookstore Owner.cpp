class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int start = 0, end = X;
        int temp = 0;
        int maxi = INT_MIN;
        for(int i=0;i<end;i++){
            temp += grumpy[i] == 1 ? customers[i] : 0;
        }
        maxi = temp;
        int n = customers.size();
        while(end<n){
            temp -= grumpy[start] == 1 ? customers[start] : 0;
            temp += grumpy[end] == 1 ? customers[end] : 0; 
            maxi = max(maxi,temp);
            start++;
            end++;
        }
        int ans = maxi;
        for(int i=0;i<n;i++){
            ans += grumpy[i] == 0 ? customers[i] : 0;
        }
        return ans;
    }
};

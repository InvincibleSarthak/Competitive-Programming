class Solution {
public:
    int trap(vector<int>& height) {
        int m = height.size();
        if(m == 0 || m == 1){
            return 0;
        }
        int left[m];
        int right[m];
        left[0] = height[0];
        int temp = height[0];
        for(int i=1;i<m;i++){
            temp = max(temp,height[i]);
            left[i] = temp;
        }
        right[m-1] = height[m-1];
        temp = height[m-1];
        for(int i=m-2;i>=0;i--){
            temp = max(temp,height[i]);
            right[i] = temp;
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            ans += (min(left[i],right[i]) - height[i]);
        }
        return ans;
    }
};

//Minimize diff between biggest and smallest tower

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int small = arr[0];
        int big = arr[n-1];
        int ans = big - small;
        
        small = arr[0] + k;
        big = arr[n-1] - k;
        if(small > big) swap(small,big);
        
        int add,subtract;
        for(int i=1;i<n-1;i++){
            add = arr[i]+k;
            subtract = arr[i]-k;
            if(add <= big || subtract >= small)   continue;
            
            if(big - subtract <= add - small){
                small = subtract;
            }
            else{
                big = add;
            }
        }
        return min(ans,big - small);
    }
};

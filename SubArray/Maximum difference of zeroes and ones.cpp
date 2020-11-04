class Solution{
public:	
	int maxSubstring(string S)
	{
	    int n = S.length();
	    int arr[n];
	    for(int i=0;i<n;i++){
	        arr[i] = (S[i] == '1' ? -1 : 1); 
	    }
	    int ans = -1,curr = 0;
	    for(int i=0;i<n;i++){
	        curr += arr[i];
	        if(curr < 0)    curr = 0;
	        ans = max(ans,curr);
	    }
	    return ans == 0 ? -1 : ans;
	}
};

class Solution{

	public:
	int solve(int a[], int n, int b[], int m, int diff){
	    int temp;
	    for(int i=0;i<n;i++){
	        temp = a[i] - diff;
	        int start=0,end=m-1,mid;
	        while(start<=end){
	            mid = (end-start)/2 + start;
	            if(b[mid] == temp){
	                return 1;
	            }
	            else if(b[mid] < temp){
	                start = mid+1;
	            }
	            else{
	                end = mid-1;
	            }
	        }
	    }
	    return -1;
	}
	int findSwapValues(int A[], int n, int B[], int m)
	{
	    int sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            sum1 += A[i];
        }
        for(int i=0;i<m;i++){
            sum2 += B[i];
        }
        int diff = abs(sum1-sum2);
        if(diff%2 != 0 || diff == 0 || n == 0 || m == 0)   return -1;
        
        sort(A,A+n);
        sort(B,B+m);
        
        diff /= 2;
        return sum1 > sum2 ? solve(A,n,B,m,diff) : solve(B,m,A,n,diff);
	}
};

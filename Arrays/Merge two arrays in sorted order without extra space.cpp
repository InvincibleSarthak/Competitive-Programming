class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    int gap = ((m-n)>>1) + n;
	    int index;
	    while(gap > 0){
	        int left = 0, right = gap;
	        while(right<(m+n)){
	            if(left < n){
    	            if(right > n-1){
    	                index = right-n;
    	            
    	                if(arr2[index] < arr1[left])swap(arr1[left],arr2[index]);
    	            }
    	            else{
    	                index = right;
    	                
    	                if(arr1[index] < arr1[left])swap(arr1[left],arr1[index]);
    	            }    
	            }
	            else{
	                index = right - n;
    	            if(arr2[index] < arr2[left-n])swap(arr2[left-n],arr2[index]);
	            }
	            right++;
	            left++;
	        }
	        gap = gap>>1;
	    }
	    sort(arr1,arr1+n);
	    sort(arr2,arr2+m);
	}
};

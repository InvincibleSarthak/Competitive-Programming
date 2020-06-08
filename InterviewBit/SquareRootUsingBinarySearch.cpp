int Solution::sqrt(int A) {
    long long int low = 1;
    long long int high = A;
    int mid;
    while(low<high){
        mid = (low+high)/2;
        if(mid > A/mid){
            high = mid-1;
        }
        else if(mid < A/mid){
            low = mid+1;
            if(low > A/low) return mid;
        }    
        else return mid;    
    }
    if(A==1){
        return 1;
    }
    else if(A==0)   return 0;
    return low;
}

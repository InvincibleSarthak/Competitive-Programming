int Solution::searchInsert(vector<int> &A, int B) {
    int high = A.size()-1;
    int low = 0;
    int mid = low;
    while(low<=high){
        mid = (low+high)/2;
        if(A[mid]<B){
            if(mid  == A.size()-1)  break;
            if(A[mid+1]>B){
               mid= mid+1;
               break; 
            }  
            low = mid+1;
        }
        else if(A[mid]>B){
            if(mid == 0)    break;
            if(A[mid-1]<B)  break;
            high = mid - 1;
        }
        else{
            return mid;
        }
    }
    if(A.size() == 1){
        if(A[0] != B){
            return 1;
        }
        else{
            return 0;
        }    
    }
    else{
        if(mid == A.size()-1)   return mid+1;
        else if(mid == 0)   return 0;
        return mid;
    }
}

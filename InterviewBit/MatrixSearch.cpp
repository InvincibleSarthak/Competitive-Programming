//Return 1 if the element is present in the matrix else return 0;
// Matrix is sorted (obviously)


int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n = A.size();
    int m = A[0].size();
    bool found = false;
    for(int i = 0;i < n; i++){
        if(A[i][0]<=B && A[i][m-1]>=B){
            int low = 0;
            int high = m-1;
            int mid;
            while(low<=high){
                mid = (low+high)/2;
                if(A[i][mid] > B){
                    high = mid - 1;
                }
                else if(A[i][mid] < B){
                    low = mid + 1;
                }
                else{
                    return 1;
                }
            }
        }
    }
    if(!found)  return 0;
}

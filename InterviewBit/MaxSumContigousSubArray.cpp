int Solution::maxSubArray(const vector<int> &A) {
    int m = A.size();
    int tempMax=0, maxAns=0;
    for(int i=0;i<m;i++){
        tempMax += A[i];
        if(tempMax>maxAns){
            maxAns=tempMax;
        }
        else if(tempMax < 0){
            tempMax=0;
        }
    }
    if(maxAns == 0){
        return *max_element(A.begin(),A.end());
    }
    return maxAns;
}

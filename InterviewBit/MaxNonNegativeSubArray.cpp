/*
Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array.

Find and return the required subarray.

NOTE:

    1. If there is a tie, then compare with segment's length and return segment which has maximum length.
    2. If there is still a tie, then return the segment with minimum starting index.

*/

vector<int> Solution::maxset(vector<int> &A) {
    int m = A.size();
    long long int sum=0,maxSum=INT_MIN;
    int start=0,end=-1;
    int tempStart=0,tempEnd=0;
    long long int lastSum;
    int countPos=0;
    for(int i=0;i<m;i++){
        if(A[i]<0){
            sum=0;
            tempStart = i+1;
            tempEnd = i+1;
        }
        else{
            sum += A[i];
            lastSum = maxSum;
            maxSum = max(maxSum,sum);
            if(maxSum > lastSum ){
                end = tempEnd;
                start = tempStart;
            }
            if(maxSum == lastSum && (sum == maxSum)){
                if((tempEnd - tempStart) > (end - start)){
                    end = tempEnd;
                    start = tempStart;
                }    
            }
            tempEnd++;
        }
    }
    if(countPos == m)   end=m-1;
    vector<int>ans;
    for(int i=start;i<=end;i++){
        ans.push_back(A[i]);
    }
    return ans;
}

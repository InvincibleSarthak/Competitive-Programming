/*
Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.
*/

int Solution::solve(vector<int> &A) {
    int m = A.size();
    int big[m];
    int temp;
    sort(A.begin(),A.end());
    for(int i=0;i<m;i++){
        temp=i;
        while(A[temp+1] == A[i] && temp<=m-2){
            temp++;
        }
        big[i] = m-1-temp;
        if(big[i] == A[i])  return 1;
    }
    return -1;
}

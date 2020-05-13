/*

You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:<ul>

LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (i>j). If multiple A[j]’s are present in multiple positions, the LeftSpecialValue is the maximum value of j.

RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (j>i). If multiple A[j]s are present in multiple positions, the RightSpecialValue is the minimum value of j.

Write a program to find the maximum special product of any integer in the array.

Input: You will receive array of integers as argument to function.

Return: Maximum special product of any integer in the array modulo 1000000007.

Note: If j does not exist, the LeftSpecialValue and RightSpecialValue are considered to be 0.

Constraints 1 <= N <= 10^5 1 <= A[i] <= 10^9
*/


int Solution::maxSpecialProduct(vector<int> &A) {
    int m = A.size();
    stack<int>s;
    int left[m],right[m];
    s.push(A[0]);
    left[0]=0;
    right[m-1]=0;
    for(int i=1;i<m;i++){
        while(s.top()<=A[i]){
            s.pop();
            if(s.empty()){
                left[i] = 0;
                break;
            }   
        }
        if(!s.empty()){
            int temp = i;
            while(temp>=0){
                if(A[temp] == s.top()){
                    left[i] = temp;
                    break;
                }
                temp--;
            }
        }    
        s.push(A[i]);
    }
    stack<int>s1;
    s1.push(A[m-1]);
    for(int i=m-2;i>=0;i--){
        while(s1.top()<=A[i]){
            s1.pop();
            if(s1.empty()){
                right[i] = 0;
                break;
            }   
        }
        if(!s1.empty()){
            int temp = i;
            while(temp<=m-1){
                if(A[temp] == s1.top()){
                    right[i] = temp;
                    break;
                }
                temp++;
            }
        }
        s1.push(A[i]);
    }
    long long int prod[m],best=0;
    for(int i=0;i<m;i++){
        long long int temp1 = (left[i]%1000000007)*(right[i]%1000000007);
        prod[i] = (temp1%1000000007);
        best=max(best,prod[i]);
    }
    return best;
}

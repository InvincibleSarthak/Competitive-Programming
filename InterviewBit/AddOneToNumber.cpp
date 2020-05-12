/*
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.
*/

#include<bits/stdc++.h>
vector<int> Solution::plusOne(vector<int> &A) {
    long long int m = A.size();
    long long int num=0,temp;
    vector<int>ans;
    if(A[m-1] != 9){
        A[m-1]++;
    }
    else{
        int i=m-1;
        while(A[i]==9 && i>-1){
            A[i]=0;
            i--;
        }
        if(i != -1) A[i]++;    
    }
    int j=0;
    while(A[j]==0 && j<m){
        j++;
    }
    if(j == m){
        ans.push_back(1);
        for(int k=0;k<m;k++){
            ans.push_back(A[k]);
        }    
    }
    else{
        for(int k=j;k<m;k++){
            ans.push_back(A[k]);
        }
    }
    return ans;
}

//To return the pair of integers in the given array whose XOR is the minimum.
//Concept: An integer will have min XOR value with the nearest integer.


int Solution::findMinXor(vector<int> &A) {
    int ans = INT_MAX;
    sort(A.begin(),A.end());
    for(int i = 0; i<A.size()-1; i++){
        ans = min (A[i]^A[i+1],ans);
    }
    return ans;
}

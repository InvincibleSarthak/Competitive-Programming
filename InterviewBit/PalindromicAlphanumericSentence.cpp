int Solution::isPalindrome(string A) {
    transform(A.begin(),A.end(),A.begin(),::toupper);
    int n = A.length();
    int i = 0;
    int j = n-1;
    while(i<=j){
        if(!isalnum(A[i]) || !isalnum(A[j])){
            if(!isalnum(A[i])){
                i++;
            }
            if(!isalnum(A[j])){
                j--;
            }
        }
        else{
            if(A[i] != A[j]){
                return 0;
            }
            else    i++,j--;
        }
    }
    return 1;
}

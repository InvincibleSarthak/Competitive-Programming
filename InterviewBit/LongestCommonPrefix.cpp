//To return the longest common prefix in the vector of strings given as input


string Solution::longestCommonPrefix(vector<string> &A) {
    sort(A.begin(),A.end());
    int len = min(A[0].length(),A[A.size()-1].length());
    int temp = 0;
    string s;
    while(temp<len){
        if(A[0][temp] != A[A.size()-1][temp])   break;
        s.push_back(A[0][temp]);
        temp++;
    }
    return s;
}

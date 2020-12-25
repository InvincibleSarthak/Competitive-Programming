/*
Ramu has an array of strings. He want to find a string s such that it is a concatenation of sub-sequence of given array and have unique characters.Since,he has just started coding so he needs your help.
A sub-sequence of an array is a set of elements that can be obtained by deleting some elements(posssibly none) from the array and keeping the order same.
Print the maximum possible length of s.
*/

#include <bits/stdc++.h>
using namespace std;
int solve(vector<string>&input, int index, string temp){
    
    if(index == input.size()){
        if(temp.length() > 26){
            return 0;
        }
        int freq[26] = {0};
        for(int i=0;i<temp.length();i++){
            if(freq[temp[i]-'a'] == 1)  return 0;
            freq[temp[i]-'a']++;
        }
        return temp.length();
    }
    int op1,op2;
    op1 = op2 = INT_MIN;
    if(input[index].length() + temp.length() <= 26) op1 = solve(input,index+1,temp+input[index]);
    op2 = solve(input,index+1,temp);
    return max(op1,op2); 
}
int main(){
    int n;
    cin>>n;
    vector<string>input;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        input.push_back(s);
    }
    string temp = "";
    cout<<solve(input,0,temp);
}

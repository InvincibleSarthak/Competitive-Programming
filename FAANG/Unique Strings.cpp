/*
  Sheldon Cooper has a string which consists only of lowercase letters. But, the problem is that he don't like duplicate characters ,so he want to remove duplicate letters so 
that every letter appears once. Since he is busy with some work at University, he needs your help.
So, you have to print the lexicographically minimum possible string with all unique characters.
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int lastOcc[26];
    int n = s.length();
    for(int i=0;i<n;i++){
        lastOcc[s[i]-'a']=i;
    }
    bool present[26]={false};
    stack<char>op;
    for(int i=0;i<n;i++){
        if(!present[s[i]-'a']){
            if(op.empty()){
                op.push(s[i]);
                present[s[i]-'a'] = true;
            }
            else{
                while((!op.empty()) && (op.top()>s[i]) && (lastOcc[op.top()-'a']>i)){
                    present[op.top()-'a'] = false;
                    op.pop();
                }
                op.push(s[i]);
                present[s[i]-'a'] = true;
            }
        }
    }
    string ans = "";
    while(!op.empty()){
        ans += op.top();
        op.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}

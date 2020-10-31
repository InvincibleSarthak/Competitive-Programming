#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    stack<int>st;
	    int n = s.length();
	    int left,right;
	    for(int i=0;i<n;i++){
	        if(s[i]-'0' >= 0 && s[i]-'0' <= 9){
	            st.push(s[i]-'0');
	        }
	        else{
	            right = st.top();
	            st.pop();
	            left = st.top();
	            st.pop();
	            switch(s[i]){
	                case '*':
	                st.push(left*right);
	                break;
	                
	                case '/':
	                st.push(left/right);
	                break;
	                
	                case '+':
	                st.push(left+right);
	                break;
	                
	                case '-':
	                st.push(left-right);
	                break;
	                
	                default:
	                break;
	            }
	        }
	    }
	    cout<<st.top()<<'\n';
	    st.pop();
	}
	return 0;
}

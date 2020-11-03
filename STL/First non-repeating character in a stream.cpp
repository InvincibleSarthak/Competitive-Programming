#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int count[26] = {0};
	    char temp;
	    queue<char>q;
	    while(n--){
	        cin>>temp;
	        count[temp-'a']++;
	        q.push(temp);
	        while(!q.empty()){
	            if(count[q.front()-'a'] > 1){
	               q.pop(); 
	            }
	            else{
	                cout<<q.front()<<' ';
	                break;
	            }
	        }
	        if(q.empty())   cout<<-1<<' ';
	    }
	    cout<<'\n';
	}
	return 0;
}

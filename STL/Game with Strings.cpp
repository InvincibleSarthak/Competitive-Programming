#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int k;
        cin>>k;
        int n = s.length();
        map<char,int>f;
        for(int i=0;i<n;i++){
            f[s[i]]++;
        }
        priority_queue<int>pq;
        for(auto it: f){
            if(it.first > 0)  pq.push(it.second);  
        }
        while(k--){
            int temp = pq.top();
            pq.pop();
            pq.push(temp-1);
        }
        int ans = 0;
        while(!pq.empty()){
            ans += (pq.top()*pq.top());
            pq.pop();
        }
        cout<<ans<<'\n';
    }
	return 0;
}

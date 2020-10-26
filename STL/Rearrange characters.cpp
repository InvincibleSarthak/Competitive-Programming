#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        int n = s.length();
        
        map<char,int>m;
        for(auto it: s){
            m[it]++;
        }
        priority_queue<pair<int,char>>p;
        for(auto it: m){
            p.push({it.second,it.first});
        }
        char prec = '#';
        int pref = -1;
        string ans = "";
        while(!p.empty()){
            pair<int,char>temp = p.top();
            p.pop();
            
            ans += temp.second;
            
            if(pref > 0){
                p.push({pref,prec});
            }
            
            temp.first--;
            prec = temp.second;
            pref = temp.first;
        }
        if(n == ans.length())   cout<<"1"<<'\n';
        else    cout<<"0"<<'\n';
    }
	return 0;
}

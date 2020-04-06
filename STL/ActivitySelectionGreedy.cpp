#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> a, pair<int,int> b){
    return a.second<=b.second; 
}
int main() {
	int t;
	cin>>t;
	vector< pair<int, int> > p;
    vector< int > start;
    vector< int > end;
	while(t--){
		int n;
        int ans = 1;
        int endTime,startTime;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>startTime;
            start.push_back(startTime);
		}
		for(int i=0;i<n;i++){
			cin>>endTime;
            end.push_back(endTime);
		}
        for(int i=0;i<n;i++){
			p.push_back(make_pair(start[i],end[i]));
		}
		sort(p.begin(),p.end(),comp);
        int last=p[0].second;
		for(int i=0;i<n-1;i++){
            if(p[i+1].first >= last){
                ans++;
				last=p[i+1].second;
            }
        }
        cout<<ans<<'\n';
		p.clear();
        start.clear();
        end.clear();
	}
}

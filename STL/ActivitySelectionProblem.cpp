//Sort according to the end time and then compare the end time with the start time of the next job.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>p1, pair<int,int>p2){
	return p1.second<p2.second;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int,int> >vec;
		int temp1,temp2;
		for(int i=0;i<n;i++){
			cin>>temp1>>temp2;
			vec.push_back(make_pair(temp1,temp2));
		}
		sort(vec.begin(),vec.end(),comp);
		temp1 = vec[0].second;
		int count = 1;
		for(int i=0;i<n-1;i++){
			if(temp1 <= vec[i+1].first){
				temp1 = vec[i+1].second;
				count++;
			}
		}
		cout<<count<<'\n';
	}
}

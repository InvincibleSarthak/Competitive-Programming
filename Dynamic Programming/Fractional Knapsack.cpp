#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool comp(pair<float,int>p1, pair<float,int>p2){
    return p1.first > p2.first;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,wt;
	    cin>>n>>wt;
	    float val[n],w[n];
	    vector<pair<float,int>>frac;
	    for(int i=0;i<n;i++){
	        cin>>val[i]>>w[i];
	        frac.push_back({val[i]/w[i],i});
	    }
	    sort(frac.begin(),frac.end(),comp);
	    float curr = 0, ans = 0;
	    for(auto it: frac){
	        if(curr + w[it.second] <= wt){
	            curr += w[it.second];
	            ans += val[it.second];
	        }
	        else{
	            ans += ((float)(wt - curr)*val[it.second])/(float)(w[it.second]);
	            break;
	        }
	    }
	    cout<<round(100*ans)/100.0<<'\n';
	}
	return 0;
}

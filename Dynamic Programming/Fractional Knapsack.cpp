#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Time O(nlogn) Space O(n)
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

// Time O(nlogn) Space O(1)
bool comp(Item a, Item b){
    double r1 = (double)(a.value)/(double)(a.weight);
    double r2 = (double)(b.value)/(double)(b.weight);
    return r1>r2;
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr,arr+n,comp);
    int temp = 0;
    double ans = 0.0;
    for(int i=0;i<n;i++){
        if(temp+arr[i].weight <= W){
            temp += arr[i].weight;
            ans += arr[i].value;
        }
        else{
            int remain = W-temp;
            ans += ((double)remain/arr[i].weight)*arr[i].value;
            break;
        }
    }
    return ans;
}

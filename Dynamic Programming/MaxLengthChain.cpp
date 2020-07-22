#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<pair<int,int> >vec, int n){
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i] = 1;
    }
    int best = -1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(vec[j].second < vec[i].first){
                int count = 1 + dp[j];
                dp[i] = max(dp[i],count);
            }
        }
        best = max(best,dp[i]);
    }
    return best;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int, int> > vec;
        int temp1,temp2;
        for(int i=0;i<n;i++){
            cin>>temp1>>temp2;
            vec.push_back(make_pair(temp1,temp2));
        }
        sort(vec.begin(),vec.end());
        cout<<solve(vec,n)<<'\n';
    }
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>vec;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        vec.push_back(temp);
    }
    int sum = 0;
    int count = 0;
    map<int,int>m;
    for(int i=0;i<n;i++){
        sum += vec[i];
        if(sum == k){
            count++;
        }
        if(m.find(sum-k) != m.end()){
            count += m[sum-k];
        }
        m[sum]++;
    }
    cout<<count<<'\n';    
}

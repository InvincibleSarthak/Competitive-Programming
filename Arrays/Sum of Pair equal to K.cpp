#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int>arr;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        arr.push_back(temp);
    }
    int k;
    cin>>k;
    unordered_set<int>s;
    for(int i=0;i<n;i++){
        temp = k - arr[i];
        if(s.find(temp) != s.end()){
            cout<<arr[i]<<' '<<temp<<'\n';
        }
        s.insert(arr[i]);
    }
}

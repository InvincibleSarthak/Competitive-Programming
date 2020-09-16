#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    if(n == 0){
        return 0;
    }
    vector<int>arr;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        arr.push_back(temp);
    }
    int k;
    cin>>k;
    int count = 1;
    map<int,int>map;
    map.insert(make_pair(arr[0],1));
    for(int i=1;i<k;i++){
        if(map.find(arr[i]) != map.end()){
            map[arr[i]]++;
        }
        else    map.insert(make_pair(arr[i],1)),count++;
    }
    cout<<count<<' ';
    for(int i=k;i<n;i++){
        if(map[arr[i-k]] == 1){
            map.erase(arr[i-k]);
            count--;
        }
        if(map[arr[i-k]] > 1){
            map[arr[i-k]]--;
        }
        if(map.find(arr[i]) != map.end()){
            if(map[arr[i]] == 0)    count++;
            map[arr[i]]++;
        }
        if(map.find(arr[i]) == map.end()){
            count++;
            map.insert(make_pair(arr[i],1));
        }
        cout<<count<<' ';
    }
}

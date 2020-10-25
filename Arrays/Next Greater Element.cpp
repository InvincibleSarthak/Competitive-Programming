/*
Given an array A of size N having distinct elements, the task is to find the next greater element for each element of the array 
in order of their appearance in the array. If no such element exists, output -1
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        stack<long long int>s;
        long long int ans[n];
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top() <= arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i] = -1;
            }
            else    ans[i] = s.top();
            s.push(arr[i]);
        }
        for(auto it: ans){
            cout<<it<<' ';
        }
        cout<<'\n';
    }
}

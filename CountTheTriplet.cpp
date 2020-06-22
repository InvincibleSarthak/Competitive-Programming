/*
Given an array of distinct integers. 
The task is to count all the triplets such that sum of two elements equals the third element.
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
        int arr[n];
        int maxVal = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            maxVal = max(arr[i],maxVal);
        }
        int freq[maxVal + 1]={0};
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        int ans = 0;
        // 0 0 0
        ans += freq[0]*(freq[0]-1)*(freq[0]-2)/6;
        // 0 x x
        for(int i=1;i<=maxVal;i++){
            ans += freq[0]*freq[i]*(freq[i]-1)/2;
        }
        // x x 2x
        for(int i=1;2*i<=maxVal;i++){
            ans += freq[2*i]*freq[i]*(freq[i]-1)/2;
        }
        // x y x+y
        for(int i=1;i<=maxVal;i++){
            for(int j=i+1;i+j<=maxVal;j++){
                ans += freq[i]*freq[j]*freq[i+j];
            }
        }
        if(ans == 0)    cout<<-1<<'\n';
        else    cout<<ans<<'\n';
    }
}

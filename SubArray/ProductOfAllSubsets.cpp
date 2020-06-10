//Every number occurs for 2^(n-1) times in the subsets.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(int *arr, int n, long long int &result){
    for(int i=0;i<n;i++){
        result  *= arr[i]; 
    }
    result = pow(result,pow(2,n-1));
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long int result = 1;
    solve(arr,n,result);
    cout<<result<<'\n';
}

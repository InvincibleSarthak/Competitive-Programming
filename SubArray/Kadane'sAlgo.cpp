/*
Kadane's Algorithm is used to calculate the maximum sum of any sub-array
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int sum = arr[0], maxSum = arr[0];
        for(int i=1;i<n;i++){
            sum = max(arr[i],sum+arr[i]);
            if(sum>maxSum)  maxSum = sum;
        }
        cout<<maxSum<<'\n';
    }
	return 0;
}

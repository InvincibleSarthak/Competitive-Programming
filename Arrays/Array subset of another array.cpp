/*
Sort both the arrays. Traverse both the arrays, if we come to a point when arr1[i] > arr2[j], this means arr2[j] was not present in arr1. Therefore arr2 is not the subset of arr1.
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int m,n;
	    cin>>m>>n;
	    int arr1[m],arr2[n];
	    for(int i=0;i<m;i++){
	        cin>>arr1[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>arr2[i];
	    }
	    sort(arr1,arr1+m);
	    sort(arr2,arr2+n);
	    string ans = "Yes";
	    if(m<n) ans = "No";
	    else{
	        int i=0,j=0;
	        while(i<m && j<n){
	            if(arr1[i] == arr2[j]){
	                i++;
	                j++;
	            }
	            else if(arr1[i] < arr2[j]){
	                i++;
	            }
	            else{
	                ans = "No";
	                break;
	            }
	        }
	    }
	    cout<<ans<<'\n';
	}
	return 0;
}

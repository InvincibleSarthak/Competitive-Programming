//max heap of left side of the median and min heap of right side of the median



#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	
	priority_queue<double>left;
	priority_queue<double,vector<double>,greater<double>>right;
	
	left.push(arr[0]);
	cout<<arr[0]<<'\n';
	double median = arr[0];
	for(int i=1;i<n;i++){
	    double x = arr[i];
	    if(left.size() == right.size()){
	        if(x < median){
	            left.push(x);
	            median = left.top();
	        }
	        else{
	            right.push(x);
	            median = right.top();
	        }
	        
	    }
	    else if(left.size() > right.size()){
	        if(x < median){
	            right.push(left.top());
	            left.pop();
	            left.push(x);
	        }
	        else{
	            right.push(x);
	        }
	        median = (left.top() + right.top())/2.0;
	    }
	    else{
	        if(x < median){
	            left.push(x);
	        }
	        else{
	            left.push(right.top());
	            right.pop();
	            right.push(x);
	        }
	        median = (left.top() + right.top())/2.0;
	    }
	    cout<<median<<'\n';
	}
	
	return 0;
}

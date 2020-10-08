/*
Given arrival and departure times of all trains that reach a railway station. Your task is to find the minimum number of platforms required for the railway station so that no train waits.

Note: Consider that all the trains arrive on the same day and leave on the same day. Also, arrival and departure times will not be same for a train, but we can have arrival time of one train equal to departure of the other. In such cases, we need different platforms, i.e at any given instance of time, same platform can not be used for both departure of a train and arrival of another.

Input:
The first line of input contains T, the number of test cases. For each test case, first line will contain an integer N, the number of trains. Next two lines will consist of N space separated time intervals denoting arrival and departure times respectively.
Note: Time intervals are in the 24-hour format(hhmm),  of the for HHMM , where the first two charcters represent hour (between 00 to 23 ) and last two characters represent minutes (between 00 to 59).

Output:
For each test case, print the minimum number of platforms required for the trains to arrive and depart safely.
*/




#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>p1 , pair<int,int>p2){
    if(p1.first == p2.first)    return p1.second > p2.second;
    return p1 < p2;
}
int main() {
	// 9(1) 9:10(-1) 9:40(2) 9:50(3) 11:00(4) 11:20(-3) 11:30(-4) 
	//12:00(-2) 15:00(5) 18:00(6) 19:00(-5) 20:00(-6)
	
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    int d[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    for(int j=0;j<n;j++){
	        cin>>d[j];
	    }
	    vector<pair<int,int>>temp;
	    for(int i=1;i<=n;i++){
	        temp.push_back({a[i-1],i});
	        temp.push_back({d[i-1],-i});
	    }
	    sort(temp.begin(),temp.end(),comp);
	    int count = 0;
	    int ans = 1;
	    for(auto it:temp){
	        if(it.second > 0)   count++;
	        else count--;
	        ans = max(ans,count);
	    }
	    cout<<ans<<'\n';
	}
	return 0;
}

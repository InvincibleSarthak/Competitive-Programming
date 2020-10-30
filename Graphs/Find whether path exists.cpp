#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isValid(int a, int n){
    return (a>=0 && a<n);
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n][n];
	    pair<int,int>source, destination;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin>>arr[i][j];
	            if(arr[i][j] == 1)  source = {i,j};
	            if(arr[i][j] == 2)  destination = {i,j};
	        }
	    }
	    
	    queue<pair<int,int>>q;
	    map<pair<int,int>,bool>visited;
	    
	    visited[source] = true;
	    q.push(source);
	    while(!q.empty()){
	        pair<int,int>temp = q.front();
	        q.pop();
	        if(visited[destination])    break;
	        if(isValid(temp.first+1,n) && !visited[{temp.first+1,temp.second}] && arr[temp.first+1][temp.second]){
	            visited[{temp.first+1,temp.second}] = true;
	            q.push({temp.first+1,temp.second});
	        }
	        if(isValid(temp.first-1,n) && !visited[{temp.first-1,temp.second}] && arr[temp.first-1][temp.second]){
	            visited[{temp.first-1,temp.second}] = true;
	            q.push({temp.first-1,temp.second});
	        }
	        if(isValid(temp.second+1,n) && !visited[{temp.first,temp.second+1}] && arr[temp.first][temp.second+1]){
	            visited[{temp.first,temp.second+1}] = true;
	            q.push({temp.first,temp.second+1});
	        }
	        if(isValid(temp.second-1,n) && !visited[{temp.first,temp.second-1}] && arr[temp.first][temp.second-1]){
	            visited[{temp.first,temp.second-1}] = true;
	            q.push({temp.first,temp.second-1});
	        }
	    }
	    
	    if(visited[destination])    cout<<"1"<<'\n';
	    else    cout<<"0"<<'\n';
	}
	return 0;
}

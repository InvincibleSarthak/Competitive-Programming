//The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph. 
//The Graph is represented as Adjancency Matrix, and the Matrix denotes the weight of the edegs (if it exists) else INF (1e7).



#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int v;
	    cin>>v;
	    vector<vector<int>>vec(v,vector<int>(v,0));
	    int dist[v][v];
	    int temp;
	    for(int i=0;i<v;i++){
	        for(int j=0;j<v;j++){
	            cin>>temp;
	            vec[i][j] = temp;
	            dist[i][j] = vec[i][j];
	        }
	    }
	    
	    
	    for(int k=0;k<v;k++){
	        for(int i=0;i<v;i++){
	            for(int j=0;j<v;j++){
	                if(dist[i][k] + dist[k][j] < dist[i][j])    dist[i][j] = dist[i][k] + dist[k][j];
	            }
	        }
	    }
	    
	    for(int i=0;i<v;i++){
	        for(int j=0;j<v;j++){
	            if(dist[i][j] == 10000000)  cout<<"INF"<<' ';
	            else    cout<<dist[i][j]<<' ';
	        }
	        cout<<'\n';
	    }
	}
	return 0;
}

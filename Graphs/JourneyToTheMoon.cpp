#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long int nCr(long long int n, long long int r){
    if(r > n-r) r=(n-r);
    long long int res = 1;
    for(long long int i=0;i<r;i++){
        res *= (n-i);
        res /= i+1;
    }
    return res;
}
template<typename T>
class Graph{
    map<long long int,vector<long long int>>adjList;
    public:
    void addEdge(T a, T b, bool bidir = true){
        adjList[a].push_back(b);
        if(bidir)   adjList[b].push_back(a);
    }
    void dfs_helper(T node, map<long long int,bool> &visited,long long int &size){
        visited[node] = true;
        for(auto it: adjList[node]){
            if(!visited[it]){
                size++;
                dfs_helper(it,visited,size);
            }  
        }
    }
    long long int dfs(){
        map<long long int,bool>visited;
        long long int component = 0;
        for(auto it: adjList){
            visited[it.first] = false;
        }
        long long int sum = 0;
        long long int size;
        for(auto it: adjList){
            size = 1;
            if(!visited[it.first]){
                dfs_helper(it.first,visited,size);
                component++;
            }
            // cout<<size<<' '<<component<<'\n';
            sum += (size>=2)?(nCr(size,2)):0; 
        }
        return sum;
    }
    void print(){
        for(auto it: adjList){
            cout<<it.first<<"->";
            for(auto itr: it.second){
                cout<<itr<<',';
            }
            cout<<'\n';
        }
    }
};

int main(){
    Graph<long long int>g;
    long long int n,m;
    cin>>n>>m;
    long long int a,b;
    for(long long int i=0;i<m;i++){
        cin>>a>>b;
        g.addEdge(a,b);
    }
    for(long long int i=0;i<n;i++){
        g.addEdge(i,i);
    }
    // g.print();
    long long int ans = g.dfs();
    ans = nCr(n,2) - ans;
    cout<<ans<<'\n';
}

//To find the shortest distance between the source and other nodes using the concept of Breadth First Search.


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    map<T,vector<T>>adjList;
    public:
    void addEdge(T a, T b, bool bidir = true){
        adjList[a].push_back(b);
        if(bidir) adjList[b].push_back(a);
    }
    void bfs(T src){
        queue<T>q;
        map<T,int>dist;
        for(auto it:adjList){
            dist[it.first]=INT_MAX;  //distance of all nodes initialized to INT_MAX
        }
        q.push(src);
        dist[src]=0;
        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(auto it:adjList[node]){ //it is child node and node is the parent node here
                if(dist[it]==INT_MAX){
                    q.push(it);
                    dist[it]=dist[node] + 1;
                } 
            }
        }
        for(auto it:adjList){
            cout<<"Distance of "<<it.first<<" from "<<src<<" is "<<dist[it.first]<<endl;
        }
    }
};
int main() {
    Graph<int>g;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        g.addEdge(a,b);
    }
    g.bfs(0);
}

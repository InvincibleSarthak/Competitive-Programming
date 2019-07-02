//To find the shortest distance between the source and other nodes using the concept of Breadth First Search.

#include<bits/stdc++.h>
#include<cstring>
#define INT_MAX 100002
using namespace std;
template<typename T>

class Graph{
    map<T,vector<T>>adjList;
public:
    Graph(){

    }
    void addEdge(T u, T v, bool bidir=true){
        adjList[u].push_back(v);
        if(bidir)
            adjList[v].push_back(u);
    }
    void print(){
        for(auto it:adjList){
            cout<<it.first<<"->";
            for(auto entry:it.second){
                cout<<entry<<",";
            }
            cout<<endl;
        }
    }
    void bfs(T src){
        queue<T>q;
        map<T,int> dist;
        map<T,T> parent;
        for(auto it:adjList){
            dist[it.first]=INT_MAX;
        }
        q.push(src);
        dist[src]=0;
        parent[src]=src;
        while(!q.empty()){
            T node=q.front();
            cout<<node<<" ";
            q.pop();
            //To traverse to all the neighbours or children of the node
            for(auto i:adjList[node]){
                if(dist[i]==INT_MAX){
                    q.push(i);
                    dist[i]=dist[node]+1;
                    parent[i]=node;
                }
            }
        }
        for(auto it: adjList){
            T node = it.first;
            cout<<"Distance from "<<node<<" to "<<src<<" is "<<dist[node]<<" ";
        }
        
    }
};
int main(){
    Graph <string> g;
    g.addEdge("Trump","Modi");
    g.addEdge("Putin","Modi",false);
    g.addEdge("Putin","Trump",false);
    g.addEdge("Putin","Pope",false);
    g.addEdge("Modi","Yogi");
    g.addEdge("Prabhu","Modi",false);
    g.addEdge("Yogi","Prabhu",false);
    g.bfs("Putin");

    return 0;
}

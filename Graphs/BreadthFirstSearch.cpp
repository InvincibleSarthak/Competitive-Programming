//BFS in adjacency list

#include<bits/stdc++.h>
#include<cstring>
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
        map<T,bool> visited;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            T node=q.front();
            cout<<node<<" ";
            q.pop();
            //To traverse to all the neighbours or children of the node
            for(auto i:adjList[node]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
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


/*
Output
Putin Modi Trump Pope Yogi Prabhu

*/

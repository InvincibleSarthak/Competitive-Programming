#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    map<T,vector<T> >adjList;
    T V;
    public:
    Graph(T v){
        V=v;
    }
    void addEdge(T a, T b, bool bidir = true){
        adjList[a].push_back(b);
        if(bidir)   adjList[b].push_back(a);
    }
    bool cycle_helper(T node, bool *visited, T parent){
        visited[node] = true;
        for(auto nbr: adjList[node]){
            if(!visited[nbr]){ 
            //If the node is not visited, it might be possible that a neighbour node of it, might have been visited.
            //Call recursively to visit the neighbour nodes
                bool ans = cycle_helper(nbr,visited,node);
                if(ans) return true; 
            }
            else if(nbr != parent){
            //If the node is already visited, it might also be possible that it is the parent node, so, to avoid such a case.
                return true;
            }
        }
        
        return false;
    }
    bool cycle_detection(T src){
        bool *visited = new bool[V];
        for(int i=0;i<V;i++){
            visited[i] = false;
        }
        bool ans = cycle_helper(src,visited,-1);
        return ans;
    }   
};
int main(){
    Graph<int>g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    // g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    if(g.cycle_detection(0))    cout<<"Yes";
    else    cout<<"No";    
}

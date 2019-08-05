//Topological Sorting using Depth First Search


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Graph{
    map<T,vector<T> >adjList;
    public:
    void addEdge(T a, T b, bool bidir = false){
        adjList[a].push_back(b);
        if(bidir) adjList[b].push_back(a);
    }
    void print(){
        for (auto it: adjList){
            cout<<it.first<<" ";
            for(auto i:it.second){
                cout<<i<<",";
            }
            cout<<endl;
        }
    }
    void dfs(){
        map<T,bool>visited;
        list<T>ordering;
        for(auto it:adjList){
            visited[it.first]=false; //Initializing all the values with false
        }
        for (auto it: adjList){
            T node = it.first; // parent node
            if(!visited[node]){
                dfsHelper(node,visited,ordering);
            }
        }
        for(auto it: ordering){ //Result
            cout<<it<<"-->";
        }
    }
    void dfsHelper(T node, map<T,bool>&visited,list<T>&ordering){
        visited[node]=true; //mark the visiting node as visited
        for(auto it:adjList[node]){ //visiting child nodes of the parent node
            if(!visited[it]){ //if the child node is not visited
                dfsHelper(it,visited,ordering);
            }
        }
        ordering.push_front(node); //push the node into the resulting list
    }
};
int main(){
    Graph<int>g;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        g.addEdge(a,b);
    }
    g.dfs();
}

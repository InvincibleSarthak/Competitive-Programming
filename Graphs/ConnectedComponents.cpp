//To print the components using the concept of DFS.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    map<T,vector<T>>adjList;
    public:
    Graph(){

    }
    void addEdge(T a, T b, bool bidir = true){
        adjList[a].push_back(b);
        if(bidir) adjList[b].push_back(a);
    }
    void dfs(T src){
        map<T,bool>visited;
        int component = 1;
        dfsHelper(src,visited);
        cout<<endl;
        for(auto it:adjList){
            T node = it.first;
            if(!visited[node]){
                dfsHelper(node,visited);
                cout<<endl;
                component++;
            }
        }
        cout<<"There are "<<component<<" components";
    }
    void dfsHelper(T node, map<T,bool> &visited){
        visited[node]=true;
        cout<<node<<" ";
        for(auto it:adjList[node]){
            if(!visited[it]){
                dfsHelper(it,visited);
            }
        }
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
    g.dfs(1);
}



/*
Input
8
1 2
9 10
1 3
4 5
7 8
2 4
3 5
5 6

Output
1 2 4 5 3 6 
7 8 
9 10 
There are 3 components
*/

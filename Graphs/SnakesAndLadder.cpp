#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    map<int , vector<int> > adjList;
    public:
    void addEdge(T a, T b){
        adjList[a].push_back(b);
    }
    void bfs(T src, T dest){
        map<int, int> visited;
        queue<int>q;
        for(auto it: adjList){
            visited[it.first] = INT_MAX;
        }
        visited[src]=0;
        T node;
        q.push(src);
        while(!q.empty()){
            node = q.front();
            q.pop();
            for(auto it: adjList[node]){
                if(visited[it] == INT_MAX){
                    q.push(it);
                    visited[it] = visited[node]+1;
                }
            }
        }
        cout<<visited[dest]<<'\n';
    }
};
int main(){
    Graph<int>g;
    int board[37]={0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[25] = 10;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[32] = -2;
    board[34] = -22;
    for(int i=0;i<37;i++){
        for(int dice=1;dice<=6;dice++){
            int j = i+dice;
            j += board[j];
            if(j<=36){
                g.addEdge(i,j);
            }
        }
    }
    g.bfs(0,36); 
}

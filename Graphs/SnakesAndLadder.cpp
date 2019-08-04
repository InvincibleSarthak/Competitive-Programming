//Given a 6*6 snakes and ladder game
//It will print the minimum number of moves required to win the game and the path as well

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    map<T,vector<T>>adjList;
    public:
    void addEdge(T a, T b, bool bidir = false){
        adjList[a].push_back(b);
        if(bidir) adjList[b].push_back(a);
    }
    int bfs(T src, int dest){
        map<T,int>dist;
        queue<T>q;
        map<T,T>parent;
        for(auto it:adjList){
            dist[it.first]=INT_MAX;
        }
        q.push(src);
        dist[src]=0;
        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(auto it: adjList[node]){
                if(dist[it]==INT_MAX){
                    q.push(it);
                    dist[it]=dist[node]+1;
                    parent[it]=node;
                }
            }
        }
        T temp = dest;
        while(temp!=src){
            cout<<temp<<" <- ";
            temp=parent[temp];
        }
        cout<<"0"<<endl;
        return dist[dest];
    }
};
int main(){
    Graph<int>g;
    int board[50]={0};
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[17]=-13;
    board[18]=11;
    board[20]=-14;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;
    for(int a=0;a<=36;a++){
        for(int b=1;b<=6;b++){
            g.addEdge(a,a+b+board[a+b]);
        }
    }
    cout<<g.bfs(0,36);
}

/*
36 <- 30 <- 29 <- 15 <- 0
4
*/

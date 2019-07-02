//Adjacency List (Graphs)

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<int> *l;
public:
    Graph(int v){
        V=v;
        l=new vector<int >[V];
    }
    void addEdge(int u, int v, bool bidir=true){
        l[u].push_back(v);
        if(bidir){
            l[v].push_back(u);
        }
    }
    void printAdjList(){
        for(int i=0;i<V;i++){
            cout<<i<<"->";
            for(auto it:l[i]){
                cout<<it<<",";
            }
            cout<<endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,4);

    g.printAdjList();

    return 0;
}

/*
Output:
0->1,4,
1->0,4,2,3,
2->1,3,
3->1,2,4,
4->0,1,3,
*/

//Adjacency List using Hash Map for generic data types using template

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
    g.print();

    return 0;
}

/*
Output:
Modi->Trump,Yogi,
Prabhu->Modi,
Putin->Modi,Trump,Pope,
Trump->Modi,
Yogi->Modi,Prabhu,
*/

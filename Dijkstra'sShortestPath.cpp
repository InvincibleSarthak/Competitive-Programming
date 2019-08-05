//To find the shortest path in an unweighted graph, we use BFS but in case of weighted graphs we need to use the approach of Dijkstra Algorithm


//Code:
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    unordered_map<T,list<pair<T,int> > >m;
    public:
    void addEdge(T a, T b, int dist,bool bidir = true){
        m[a].push_back(make_pair(b,dist));
        if(bidir) m[b].push_back(make_pair(a,dist));
    }
    void print(){//This will print all the elements from the adjList and their respective lists as well
        for (auto it:m){
            cout<<it.first<<"->";
            for(auto i:it.second){
                cout<<"("<<i.first<<","<<i.second<<")";
            }
            cout<<endl;
        }
    }
    void path(T src){
        map<T,int>dist;
        for(auto it: m){
            dist[it.first]=INT_MAX; //setting every node with infinite distance initially
        }
        dist[src]=0;
        set < pair<int,T> >s;
        s.insert(make_pair(0,src));
        while(!s.empty()){
            auto p = *(s.begin());//pointing to the first pair present in the set
            T node = p.second;//parent node
            int nodeDist = p.first;//Distance of the parent node
            s.erase(s.begin());
            for(auto it: m[node]){//traversing all the child nodes of the parent node 
                //it.first is a child node and it.second is the dist of that node
                if((nodeDist + it.second) <dist[it.first]){//if the new distance is less than previous distance of the node then only update the distance of the node
                    T dest = it.first;
                    //update the set by deleting the prev record and inserting the new one
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f!=s.end())  s.erase(f);

                    dist[dest]=nodeDist+it.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
        for (auto it: dist){
            cout<<"Node: "<<it.first<<" Distance: "<<it.second<<endl;
        }
    }
};
int main(){
    Graph<int>g;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,d;
        cin>>a>>b>>d;
        g.addEdge(a,b,d);
    }
    g.print();
    g.path(1);
}


/*
Input
5
1 2 1
1 3 4
1 4 7
2 3 1
3 4 2

Output
4->(1,7)(3,2)
3->(1,4)(2,1)(4,2)
1->(2,1)(3,4)(4,7)
2->(1,1)(3,1)
Node: 1 Distance: 0
Node: 2 Distance: 1
Node: 3 Distance: 2
Node: 4 Distance: 4

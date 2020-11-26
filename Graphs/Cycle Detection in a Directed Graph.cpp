bool check(int node, vector<int>adj[], bool* visited){
    visited[node] = true;
    for(auto nbr: adj[node]){
        if(visited[nbr])    return true;
        bool ans = check(nbr,adj,visited);
        if(ans) return true;
    }
    visited[node] = false;
    return false;
}


bool isCyclic(int V, vector<int> adj[])
{
    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    bool temp = false;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            temp = check(i,adj,visited);
            if(temp)    return temp;
        }
    }
    return temp;
}

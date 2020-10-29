
bool poss(vector<int>a[], int x, int y, vector<vector<bool>>&visited){
    int row = visited.size();
    int col = visited[0].size();
    
    return (x>=0 && x<row && y>=0 && y<col && a[x][y] && (!visited[x][y]));
}

void dfs(vector<int>a[], int x, int y, vector<vector<bool>>&visited ){
    visited[x][y] = true;
    int row[8] = {-1,-1,-1,0,0,1,1,1};
    int col[8] = {-1,0,1,-1,1,-1,0,1};
    
    for(int i=0;i<8;i++){
        if(poss(a,x+row[i],y+col[i],visited))   dfs(a,x+row[i],y+col[i],visited);
    }
}

int findIslands(vector<int> A[], int N, int M) {
    
    vector<vector<bool>>visited(N,vector<bool>(M,0));
    
    int ans = 0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if((A[i][j]) && (!visited[i][j])){
                dfs(A,i,j,visited);
                ans++;
            }
        }
    }
    
    return ans;
}

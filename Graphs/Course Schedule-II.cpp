/*
There are a total of n courses you have to take labelled from 0 to n - 1.

Some courses may have prerequisites, for example, if prerequisites[i] = [ai, bi] this means you must take the course bi before the course ai.

Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses.

If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

  Visited[i] = 0 (never visited)
      "      = 1 (partially visited)
      ""     = 2 (all children visited)
      
      
  check boolean to detect cycle in the graph
*/




class Solution {
    vector<int>temp;
    bool check = true;
public:
    void dfs(int node,map<int,vector<int>>& adjList, vector<int>& visited){
        if(!check)  return;
        visited[node] = 1;
        for(auto i:adjList[node]){
            if(visited[i] == 0){
                dfs(i,adjList,visited);
            }
            else if(visited[i] == 1){
                check = false;
            }   
        }
        visited[node] = 2;
        temp.push_back(node);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>visited(numCourses,0);
        map<int,vector<int>>adjList;
        for(auto it: prerequisites){
            adjList[it[1]].push_back(it[0]);
        }
        dfs(0,adjList,visited);
        for(int i=0;i<numCourses;i++){
            if(visited[i] == 0){
                dfs(i,adjList,visited);
            }
        }
        if(!check)  return vector<int>{};
        reverse(temp.begin(),temp.end());
        return temp;
    }
};

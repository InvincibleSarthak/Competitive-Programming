/*
You are in an infinite 2D grid where you can move in any of the 8 directions :

 (x,y) to 
    (x+1, y), 
    (x - 1, y), 
    (x, y+1), 
    (x, y-1), 
    (x-1, y-1), 
    (x+1,y+1), 
    (x-1,y+1), 
    (x+1,y-1) 

You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You start from the first point.
*/



#include<bits/stdc++.h>
int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int m = A.size();
    int dist = 0;
    for(int i=0;i<m-1;i++){
        int x = A[i];
        int y = B[i];
        dist += min(abs(A[i+1]-x),abs(B[i+1]-y));
        dist += abs(abs(A[i+1]-x) - abs(B[i+1]-y));
    }
    return dist;
}

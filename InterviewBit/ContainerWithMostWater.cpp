/*
Given n non-negative integers a1, a2, ..., an,
where each represents a point at coordinate (i, ai).
'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).

Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Your program should return an integer which corresponds to the maximum area of water that can be contained ( Yes, we know maximum area instead of maximum volume sounds weird. But this is 2D plane we are working with for simplicity ).


*/

int Solution::maxArea(vector<int> &A) {
    int l=0;
    int r=A.size()-1;
    int area=0;
    while(l<r)
    { 
        area=max(area,min(A[l],A[r])*(r-l));
        if(A[l]<A[r])
            l++;
        else
            r--;
    }
    return area;
}

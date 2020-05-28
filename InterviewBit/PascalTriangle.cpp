/*


Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]


*/




vector<vector<int> > Solution::solve(int A) {
    vector<vector<int> > vec(A);
    for(int i=0;i<A;i++){
        if(i == 0){
            vec[0].push_back(1);
        }
        else if(i == 1){
            vec[1].push_back(1);
            vec[1].push_back(1);
        }
        else{
            for(int j=0;j<=i;j++){
                if(j>=1 && j<=i-1)    vec[i].push_back(vec[i-1][j] + vec[i-1][j-1]);    
                else    vec[i].push_back(1);
            }    
        }
    }
    return vec;
}

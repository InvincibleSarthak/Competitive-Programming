/*
You are given an array A of N elements and Q queries. Each query consists of 3 integers L R K. For each query, you have to find the number of elements Ax1, Ax2,….,Axj>=K, where L<=x1, x2,…xj<=R.

Input Format:
First line contains an integer N, denoting the number of elements in the array A. Next line contains N integers denoting the elements of the array. Next line contains a single integer Q, denoting the number of queries. Next Q lines contains Q queries, consisting of 3 integers each, L R K.

Constraints:
1<=N,Q<=10^5 |Ai|, |K|<=10^9 1<=L, R<=N

Output Format
Print Q lines, where ith line contains the answer to the ith query.

Sample Input
5
1 2 3 4 5
5
1 4 1
1 5 2
1 5 3
1 5 4
1 5 5
Sample Output
4
4
3
2
1

*/

Code:
#include <iostream>
#define INT_MAX 999999999
using namespace std;
int queryMin(int *tree, int index, int low, int high, int qlow, int qhigh, int val){
    int k=0;
    if(qlow>high || qhigh<low){
        return k;
    }
    if(low==high){
        if(tree[index]>=val){
            k++;
        }
        return k;
    }
    int mid=(low+high)/2;
    int leftAns = queryMin(tree,2*index,low,mid,qlow,qhigh,val);
    k+=leftAns;
    int rightAns = queryMin(tree,2*index+1,mid+1,high,qlow,qhigh,val);
    k+=rightAns;
    return k;
}
void buildTree(int *arr,int low, int high, int *tree, int index){
    if(low==high){
        tree[index]=arr[low];
        return ;
    }
    int mid = (low+high)/2;
    buildTree(arr,low,mid,tree,2*index);
    buildTree(arr,mid+1,high,tree,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return ; 
}
int main() {
    int n,q;
    cin>>n;
    int arr[n];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cin>>q;
    int tree[4*n+1];
    buildTree(arr,1,n,tree,1);
    int a,b,c;
    while (q--){
        cin>>a>>b>>c;
        cout<<queryMin(tree,1,1,n,a,b,c)<<endl;
    }
}

/*
You are given an array A of n elements and Q queries. Each query can be of following types:

1 L R: Print the minimum value in AL, AL+1, AL+2….,AR.
2 X Y: Update the value of Ax with Y.
Input Format:
First line contains integers N and Q, denoting the number of elements and number of queries. Next line contains N integers, denoting A1, A2, A3….,AN. Next Q lines contains Q queries.

Constraints:
1<=N,Q<=10^5 |Ai|,|Y|<=10^9 1<=L,R,X<=N

Output Format
Answer each query of type 1.

Sample Input
5 5
1 4 3 5 2
1 1 5
2 3 9
1 2 4
1 2 5
1 3 4
Sample Output
1
4
2
5
*/


Code:
#include <iostream>
#define INT_MAX 999999999
using namespace std;
void update(int *tree, int index, int low, int high, int pos, int val){
    //Overflow
    if(low>high){
        return ;
    }
    if(pos>high || pos<low){
        return ;
    }
    //Complete Overlap
    if(low==pos && high==pos){
        tree[index]=val;
        return ;
    }
    int mid = (low+high)/2;
    update(tree,2*index,low,mid,pos,val);
    update(tree,2*index+1,mid+1,high,pos,val);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return ;
}
int queryMin(int *tree, int index, int low, int high, int qlow, int qhigh){
    //No overlap
    if(qlow>high || qhigh<low){
        return INT_MAX;
    }
    //Complete Overlap
    if(qlow<=low && qhigh>=high){
        return tree[index];
    }
    int mid=(low+high)/2;
    int leftAns = queryMin(tree,2*index,low,mid,qlow,qhigh);
    int rightAns = queryMin(tree,2*index+1,mid+1,high,qlow,qhigh);
    return min(leftAns,rightAns);
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
    cin>>n>>q;
    int arr[n];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int tree[4*n+1];
    buildTree(arr,1,n,tree,1);
    int a,l,r,x,y;
    while (q--){
        cin>>a;
        if(a==1){
            cin>>l>>r;
            cout<<queryMin(tree,1,1,n,l,r)<<endl;
        }
        else{
            cin>>x>>y;
            update(tree,1,1,n,x,y);
        }
    }
}

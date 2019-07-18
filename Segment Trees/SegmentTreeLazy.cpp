//This code contains the function for updating the segment tree using lazy propagation and then Query to print the min number 
//inside the range.

#include<iostream>
using namespace std;
int lazy[1000]={0};
void updateLazy(int tree[],int index,int qlow, int qhigh, int low, int high,int inc){
    //First step: Never we go down if you have lazy value at node, first resolve it
    if(lazy[index]!=0){
        tree[index]+=lazy[index];
        if(low!=high){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
    }
    //Out of Bounds
    if(qlow>high || qhigh<low){
        return;
    }
    //Complete Overlap
    if(qhigh>=high && qlow<=low){
        tree[index]+=inc;
        if(low!=high){
            lazy[2*index]+=inc;
            lazy[2*index+1]+=inc;
        }
        return;
    }
    int mid=(low+high)>>1;
    updateLazy(tree,2*index,qlow,qhigh,low,mid,inc);
    updateLazy(tree,2*index+1,qlow,qhigh,mid+1,high,inc);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}
int queryLazy(int tree[],int index,int qlow, int qhigh, int low, int high){
    if(lazy[index]!=0){
        tree[index]+=lazy[index];
        if(low!=high){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
    }
    //No overlap
    if(qlow>high || qhigh<low){
        return 1000002;
    }
    //Complete Overlap
    if(qlow<=low && qhigh>=high){
        return tree[index];
    }
    //Partial Overlap
    int mid=(low+high)>>1;
    int leftAns=queryLazy(tree,2*index,qlow,qhigh,low,mid);
    int rightAns=queryLazy(tree,2*index+1,qlow,qhigh,mid+1,high);
    return min(leftAns,rightAns);

}
void buildTree(int arr[],int low, int high, int tree[], int index){
    //base case
    if(low>=high){
        tree[index]=arr[low];
        return;
    }
    //recursive case
    int mid=(low+high)>>1;
    buildTree(arr,low,mid,tree,2*index);
    buildTree(arr,mid+1,high,tree,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    int tree[3*n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    buildTree(arr,0,n-1,tree,1);
    updateLazy(tree,1,0,2,0,n-1,10);
    cout<<queryLazy(tree,1,0,2,0,n-1)<<' ';
}

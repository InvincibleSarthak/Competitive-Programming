//My version of lazy propagation in segment trees


#include<iostream>
using namespace std;
void updateLazy(int *lazy, int *tree, int index, int low, int high, int qlow, int qhigh,int val){
    //No overlap
    if(qlow>high || qhigh<low){
        return ;
    }
    //complete overlap
    if(qlow<=low && qhigh>=high){
        if(low==high){
            tree[index]+=val;
            return ;
        }
        lazy[index]+=val;
        tree[index]+=lazy[index];
        lazy[2*index]+=lazy[index];
        lazy[2*index+1]+=lazy[index];
        lazy[index]=0;
        return ;
    }
    //Partial overlap
    int mid = (low+high)/2;
    updateLazy(lazy,tree,2*index,low,mid,qlow,qhigh,val);
    updateLazy(lazy,tree,2*index+1,mid+1,high,qlow,qhigh,val);
    tree[index]=min(tree[2*index],tree[2*index+1]);
}
void buildTree(int *arr, int low, int high, int *tree, int index){
    if(low==high){
        tree[index]=arr[low];
        return;
    }
    int mid =(low+high)/2;
    buildTree(arr,low,mid,tree,2*index);
    buildTree(arr,mid+1,high,tree,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int tree[4*n+1];
    int lazy[4*n+1];
    for(int i=0;i<(4*n+1);i++){
        lazy[i]=0;
    }
    buildTree(arr,1,n,tree,1);
    int l,r;
    cin>>l>>r;
    int val;
    cin>>val;
    updateLazy(lazy,tree,1,1,n,l,r,val);
    for(auto it:tree){
        cout<<it<<" ";
    }
}

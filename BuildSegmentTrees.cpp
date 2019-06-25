//To print the minimum number in the index range qs and qe using the concept of segment trees.


#include<iostream>
using namespace std;
int query(int ss, int se, int qs, int qe, int *tree, int index){
    //No overlap
    if(ss>qe || se<qs){
        return 200000;
    }   
    //Complete Overlap
    if(ss>=qs && se<=qe){
        return tree[index];
    }
    //Partial Overlap
    int mid=(ss+se)/2;
    int leftAns=query(ss,mid,qs,qe,tree,2*index);
    int rightAns=query(mid+1,se,qs,qe,tree,2*index+1);
    
    return min(leftAns,rightAns);
}
void buildTree(int arr[],int s, int e, int *tree, int index){
    if(s==e){
        tree[index]=arr[s];
        return;
    }
    int mid=(s+e)/2;
    buildTree(arr,s,mid,tree,2*index);
    buildTree(arr,mid+1,e,tree,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);

    return;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int *tree= new int [4*n+1];
    buildTree(arr,0,n-1,tree,1);
    int qs,qe;
    cin>>qs>>qe;
    for(int i=1;i<(4*n+1);i++){
    //    cout<<tree[i]<<' ';
    }
    cout<<query(0,n-1,qs,qe,tree,1)<<endl;
}

#include<iostream>
using namespace std;
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
    for(int i=1;i<(4*n+1);i++){
        cout<<tree[i]<<' ';
    }
}

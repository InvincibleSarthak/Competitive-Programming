//SPOJ problem without using LAZY PROPAGATION
//TLE 

#include <iostream>
#define INT_MAX 999999999
using namespace std;
void queryAdd(int *tree, int index, int low, int high, int qlow, int qhigh, int val){
    if(qlow>high || qhigh<low){
        return;
    }
    if(low==high){
        tree[index]+=val;
        return;
    }
    int mid = (low+high)/2;
    queryAdd(tree,2*index,low,mid,qlow,qhigh,val);
    queryAdd(tree,2*index+1,mid+1,high,qlow,qhigh,val);
    return;
}
int querySum(int *tree, int index, int low, int high, int qlow, int qhigh){
    int sum = 0;
    if(qlow>high || qhigh<low){
        return 0;
    }
    if(low==high){
        sum+=tree[index];
        return sum;
    }
    int mid = (low+high)/2;
    int leftSum = querySum(tree,2*index,low,mid,qlow,qhigh);
    sum+=leftSum;
    int rightSum = querySum(tree,2*index+1,mid+1,high,qlow,qhigh);
    sum+=rightSum;
    return sum;
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
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        int arr[n];
        for(int i=1;i<=n;i++){
            arr[i]=0;
        }
        int tree[4*n+1];
        buildTree(arr,1,n,tree,1);
        while(q--){
            int a,p,q,v;
            cin>>a;
            if(a==0){
                cin>>p>>q>>v;
                queryAdd(tree,1,1,n,p,q,v);
            }
            else{
                cin>>p>>q;
                cout<<querySum(tree,1,1,n,p,q)<<endl;
            }
        }
    }
}

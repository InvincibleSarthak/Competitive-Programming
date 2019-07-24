//My version of lazy propagation in segment trees


#define ll long long int
#include<iostream>
using namespace std;
ll arr[100005];
ll tree[400021];
ll lazy[400021];
void updateLazy(ll index, ll low, ll high, ll qlow, ll qhigh, ll val){
    //LazyNode
    if(lazy[index]!=0){
        tree[index]+=lazy[index];
        //If not at leaf node, solve for children
        if(low!=high){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
    }
    //Overflow
    if(low>high || qlow>high || qhigh<low){
        return;
    }
    //Complete Overlap
    if(low>=qlow && high<=qhigh){
        tree[index]+=val;
        if(low!=high){
            lazy[2*index]+=val;
            lazy[2*index+1]+=val;
        }
        return;
    }
    //Partial Overlap
    ll mid = (low+high)>>1;
    updateLazy(2*index,low,mid,qlow,qhigh,val);
    updateLazy(2*index+1,mid+1,high,qlow,qhigh,val);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return ;
}
void buildTree(ll index, ll low, ll high){
    //Leaf Node
    if(low==high){
        tree[index]=arr[low];
        return ;
    }
    ll mid = (low+high)>>1;
    buildTree(2*index,low,mid);
    buildTree(2*index+1,mid+1,high);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return ;
}
int main(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
    }
    buildTree(1,1,n);
    ll t;
    cin>>t;
    while(t--){
        ll qlow,qhigh,val;
        cin>>qlow>>qhigh>>val;
        updateLazy(1,1,n,qlow,qhigh,val);
        for(ll i=1;i<2*n;i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }
}

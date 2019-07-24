//SPOJ
//Successfully submitted!

#include<iostream>
#define ll long long 
using namespace std;
ll arr[100005];
ll tree[400005];
ll lazy[400005];
ll sum;
void updateLazy(ll index, ll low, ll high, ll qlow, ll qhigh, ll val){
    //LazyNode
    if(lazy[index]!=0){
        tree[index]+=(high-low+1)*lazy[index];
        if(low!=high){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
    }
    //Out of bound
    if(low>high || qlow>high || qhigh<low){
        return;
    }
    //Complete Overlap
    if(qlow<=low && qhigh>=high){
        tree[index]+=(high-low+1)*val;
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
    tree[index]=(tree[2*index]+tree[2*index+1]);
    return ;
}
void printSum(ll index, ll low, ll high, ll qlow, ll qhigh){
    //LazyNode
    if(lazy[index]!=0){
        tree[index]+=(high-low+1)*lazy[index];
        if(high!=low){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
    }
    //Out of bound
    if(high<low || qhigh<low || qlow>high){
        return;
    }
    //Complete Overlap
    if(qlow<=low && qhigh>=high){
        sum+=tree[index];
        return;
    }
    //Partial Overlap
    ll mid = (low+high)>>1;
    printSum(2*index,low,mid,qlow,qhigh);
    printSum(2*index+1,mid+1,high,qlow,qhigh);
    tree[index]=tree[2*index]+tree[2*index+1];
    return;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,c;
        cin>>n>>c;
        for(ll i=1;i<=n;i++){
            arr[i]=0;
        }
        for(ll i=1;i<=(4*n+1);i++){
            tree[i]=0;
            lazy[i]=0;
        }
        while(c--){
            int a;
            cin>>a;
            ll p,q,v;
            if(a==0){
                cin>>p>>q>>v;
                updateLazy(1,1,n,p,q,v);
            }
            else{
                cin>>p>>q;
                sum=0;
                printSum(1,1,n,p,q);
                cout<<sum<<endl;
            }
        }
    }
}

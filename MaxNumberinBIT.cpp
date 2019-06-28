//To return the maximum number in a Binary Indexed Tree till a given range.

#include<iostream>
using namespace std;
int BIT[1000]={0};
void update(int i, int val,int n){
    while(i<=n){
        BIT[i]=max(BIT[i],val);
        i+=(i&(-i));
    }
    return;
}
int query(int n){
    int ans=0;
    while(n>0){
        ans=max(ans,BIT[n]);
        n-=(n&(-n));
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        update(i,arr[i],n);
    }
    int q;
    cin>>q;
    int k;
    update(3,10,5);
    while(q--){
        cin>>k;
        cout<<query(k)<<endl;
    }
}

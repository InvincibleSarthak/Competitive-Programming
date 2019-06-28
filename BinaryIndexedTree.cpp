//To update and query a BIT
//Query: To return the sum of an array between the range l and r given as an input by the user


#include<iostream>
using namespace std;
int BIT[10000]={0};
void update(int i,int inc,int N){
    while(i<=N){
        BIT[i]+=inc;
        i+=(i&(-i));
    }
}
int query(int n){
    int ans=0;
    while (n>0){
        ans+=BIT[n];
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
    int l,r;
    while(q--){
        cin>>l>>r;
        cout<<query(r)-query(l-1)<<endl;
    }
}

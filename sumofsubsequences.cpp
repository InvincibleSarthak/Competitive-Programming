#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int t;
    int n,m,arr[1000];
    cin>>t;
    while(t>0){
        int o=0;
        cin>>n>>m;
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        for(int j=1;j<=((1<<n)-1);j++){
            int k=0,l=j;
            int sum=0;
            while(l>0){
                if((l&1)==1){
                    sum+=arr[k];    
                }
                l=l>>1;
                k++;
            }
            if(sum==m){
                o++;
            }
        }    
        if(o>0){
            cout<<"Yes";
        }
        else{
            cout<<"No";
        }
    t--;
    }
}
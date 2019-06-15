#include<bits/stdc++.h>
#include<iostream>
using namespace std;
map<long long, long long > mark[11];
long long  N=200000,k,n;
int main(){
    long long arr[N];
    cin >> n>> k;
    for(long long i =1;i<=n;i++){
        cin>>arr[i];
    }
    for(long long i=1;i<=n;i++){
        long long val=arr[i];
        for(long long j=1;j<=10;j++){
            val=(val*10)%k;
            mark[j][val]++;
        }
    }
    long long ans =0;
    for(long long i=1;i<=n;i++ ){
        long long val = arr[i];
        long long len = 0;
        while(val){
            len++;
            val=val/10;
        }
        long long power =1;
        for(long long i=1;i<=len;i++){
            power=power*10;
        }
        power=power%k;
        long long findout = (k-arr[i]%k)%k;
        ans+= mark[len][findout];
        if((power*arr[i]+ arr[i])%k == 0)
            ans--;
    }
    cout<<ans;
}
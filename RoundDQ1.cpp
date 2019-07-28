//Q1 OF Kickstart Round D
//Base Test Case done
//TLE


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int digArr[100005];
vector<int>vec;
int main(){
    int t;
    cin>>t;
    for(int j=1;j<=t;j++){
        int n,q;
        cin>>n>>q;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        while(q--){
            int index,val,max=0;
            cin>>index>>val;
            arr[index]=val;
            for(int i=1;i<=(1<<n)-1;i++){
                int k=0,l=i,sum=0, num=0;
                while(l>0){
                    if((l&1)==1){
                        sum=sum^arr[k];
                        num++;
                    }
                l=l>>1;
                k++;
                }
                int digits=0;
                while(sum>0){
                    if((sum&1)==1)
                        digits++;
                    sum=sum>>1;
                }
                if(digits%2==0){
                    if(num>max){
                        max=num;
                    }
                }
            }
            vec.push_back(max);
        }
        cout<<"Case #"<<j<<": ";
        for(auto it:vec){
            cout<<it<<" ";
        }
        cout<<endl;
        vec.clear();    
    }
}

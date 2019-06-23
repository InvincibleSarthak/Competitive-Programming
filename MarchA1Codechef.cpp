//Code to check if sum of a subset matches our input if yes, then print yes, else print No


#include<bits/stdc++.h>
using namespace std;
vector<int>vec;
int main(){
    int t,n,m,a,sum;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>a;
            vec.push_back(a);
        }
        for(int i=0;i<(1<<n);i++){
            sum=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    sum+=vec[j];
                }
            }
            if(sum==m){
                cout<<"Yes"<<endl;
                break;
            }    
        }
        if(sum!=m)
            cout<<"No"<<endl;
        vec.clear();
    }
    return 0;
}

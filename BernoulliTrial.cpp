//SPOJ:  FAVDICE


#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        float ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            ans+=(n/(i*1.0));
        }
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
    return 0;
}

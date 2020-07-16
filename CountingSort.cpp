#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char arr[n];
        char ans[n] = {' '};
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int index[26] = {0};
        for(int i=0;i<n;i++){
            index[arr[i] - 'a']++;
        }
        for(int i=1;i<26;i++){
            index[i] = index[i-1] + index[i];
        }
        for(int i=0;i<n;i++){
            ans[index[arr[i]-'a']-1] = arr[i];
            index[arr[i]-'a']--;
        }
        for(int i=0;i<n;i++){
            cout<<ans[i];
        }
        cout<<'\n';
    }
}

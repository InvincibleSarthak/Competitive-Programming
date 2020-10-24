#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        stack<int>s;
        int index = 0;
        int ans=0,tempAns;
        while(index < n){
            if(s.empty() || (arr[index] >= arr[s.top()])){
                s.push(index);
                index++;
            }
            else{
                int temp = s.top();
                s.pop();
                tempAns = arr[temp]*(s.empty() ? index : index - s.top() - 1);
                
                if(tempAns > ans)   ans = tempAns;
            }
        }
        while(!s.empty()){
            int temp = s.top();
            s.pop();
            tempAns = arr[temp]*(s.empty() ? index : index-s.top()-1);
            
            if(tempAns > ans)   ans = tempAns;
        }
        cout<<ans<<'\n';
    }
	return 0;
}

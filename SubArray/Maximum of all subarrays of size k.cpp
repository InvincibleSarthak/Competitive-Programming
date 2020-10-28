#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        deque<int>q;
        for(int i=0;i<k;i++){
            while(!q.empty() && arr[i] >= arr[q.back()])    q.pop_back();
            q.push_back(i);
        }
        for(int i=k;i<n;i++){
            cout<<arr[q.front()]<<' ';
            while(!q.empty() && q.front() <= i-k){
                q.pop_front();
            }
            while(!q.empty() && arr[i] >= arr[q.back()])    q.pop_back();
            q.push_back(i);
        }
        cout<<arr[q.front()]<<'\n';
    }
	return 0;
}

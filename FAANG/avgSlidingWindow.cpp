#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin>>k;
    int n;
    cin>>n;
    queue<int>q;
    float sum = 0, count = 0;
    while(n != (-1)){
        q.push(n);
        sum+=n;
        if(count == k){
            sum -= q.front();
            q.pop();
            count--;
        }
        count++;
        cout<<fixed<<setprecision(4)<<(sum/count)<<' ';
        cin>>n;
    }
}

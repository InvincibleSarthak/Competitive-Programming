/*
You have to given a data stream terminated by -1 and the size of sliding window. For each variation in sliding window you need to tell the average of data in current sliding 
window. Print 4 digits after the decimal point.

Input Format
First line contains an integer denoting the size of sliding window.
Second line has a data stream terminated by -1.

Constraints
None

Output Format
Print average of each sliding window.

Sample Input
5
51 62 24 51 79 33 72 78 84 42 -1
Sample Output
51.0000 56.5000 45.6667 47.0000 53.4000 49.8000 51.8000 62.6000 69.2000 61.8000 
*/



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

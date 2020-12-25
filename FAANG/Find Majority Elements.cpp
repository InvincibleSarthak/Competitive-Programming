/*
You are given an array A of size N.
Find all the elements which appear more than floor(N/3) times in the given array.
Wait Wait!
There is a condition that you have to do your job in O(N) time complexity and O(1) space complexity.

Solution approach: more than floor(N/K) times requires k-1 variables.
*/

#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int a=arr[0],b=-1;
    int counta=1,countb=0;
    for(int i=1;i<n;i++){
        if(arr[i] == a) counta++;
        else if(arr[i] == b)    countb++;
        else if(counta == 0)    counta = 1, a = arr[i];
        else if(countb == 0)    countb = 1, b = arr[i];
        else{
            counta--;
            countb--;
        }
    }
    counta=0,countb=0;
    for(int i=0;i<n;i++){
        if(arr[i] == a){
            counta++;
        }
        if(arr[i] == b){
            countb++;
        }
    }
    if(counta > n/3 || countb>n/3){
        if(counta > n/3)    cout<<a<<' ';
        if(countb > n/3)    cout<<b<<' ';
    }
    else{
        cout<<"No Majority Elements";
    }
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(int* arr, int n){ //to find out two numbers appearing in majority: first and second
    int first=INT_MAX;
    int second=INT_MAX;
    int count1=0, count2=0; // count1 stores the count for the first number whereas second stores the count for second number
    for(int i=0;i<n;i++){
        if(first == arr[i]){
            count1++;
        }
        else if(second == arr[i]){
            count2++;
        }
        else if(count1 == 0){
            first = arr[i];
            count1++;
        }
        else if(count2 == 0){
            second = arr[i];
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }
    for(int i=0;i<n;i++){
        if(first == arr[i]){
            count1++;
        }
        else if(second == arr[i]){
            count2++;
        }
    }
    if(count1 > n/3){
        return first;
    }
    else if(count2 > n/3){
        return second;
    }
    return -1;
}
 int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<solve(arr,n)<<'\n';
    }
    return 0;
}

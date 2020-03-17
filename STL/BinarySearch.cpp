//Binary Search (in-built function), Lower Bound, Upper Bound

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={10,20,30,40,40,40,50,70};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    bool present = binary_search(arr,arr+n,key);
    if(present){
        cout<<"The number is present in the array. "<<endl;
    }
    else{
        cout<<"The number is absent from the array."<<endl;
    }
    auto it1 = lower_bound(arr,arr+n,key); //first element greater than or equal to the key
    cout<<*it1<<endl;
    auto it2 = upper_bound(arr,arr+n,key); // first element greater than key
    cout<<*it2<<endl;
    cout<<it2-it1<<endl; // To print the frequency of a number in an array
    return 0;
}

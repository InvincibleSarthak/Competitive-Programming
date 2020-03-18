#include<iostream>
#include<algorithm>
using namespace std;

//Custom Comparator to sort an array in decreasing order
bool comp (int a, int b){
    return a>b;
}

int main(){
    int arr [] = {1,6,3,4,7,5};
    int n = sizeof(arr)/sizeof(int);
    sort(arr,arr+n,comp);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}

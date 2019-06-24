#include<bits/stdc++.h>
using namespace std;
void merge(int* arr,int s, int e){
    int mid=((s+e)/2);
    int i=s;
    int j=mid+1;
    int k=s;
    int temp[100];
    while(i<=mid && j<=e){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=e){
        temp[k++]=arr[j++];
    }
    for(int x=s;x<=e;x++){
        arr[x]=temp[x];
    }
}
void mergeSort(int* arr,int s, int e){
    //base case
    if(s>=e){
        return;
    }
    //recursive case
    int mid=((s+e)/2);//division of array
    mergeSort(arr,0,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
}

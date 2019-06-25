#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void merge(int arr[],int s, int e){
    int mid=(s+e)>>1;
    int i=s;
    int j=mid+1;
    int k=s;
    int temp[1000000];
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
void mergeSort(int arr[],int s, int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)>>1;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}
int main(){
    ll n=0;
    int arr[1000000];
    while(cin>>arr[n]){
        n++;
    }
    
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
}

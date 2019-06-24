//Google Interview Question
//To print max number of pages a student can read given k number of students are there and we have n number of 
//books with p number of pages each, such that the minimum number of pages are to be read by the person reading maximum number of 
//pages.


#include<iostream>
using namespace std;
#define ll long long int
bool isValid(ll arr[],ll n, ll k, ll mid){
    int students=1;
    ll current_pages=0;
    for(ll i=0;i<n;i++){
        if((current_pages+arr[i])>mid){
            current_pages=arr[i];
            students++;
            if(students>k){
                return false;
            }
        }
        else{
            current_pages+=arr[i];
        }
    }
    return true;
}
ll bookAllocate(ll arr[],ll n, ll k){
    ll total_pages=0;
    ll s=0;
    for(ll i=0;i<n;i++){
        total_pages+=arr[i];
        s=max(s,arr[i]);
    }
        ll e=total_pages;
        ll finalAns=s;
        while(s<=e){
            ll mid=(s+e)/2;
            if(isValid(arr,n,k,mid)){
                finalAns=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
    return finalAns;
}
int main(){
    ll n,k,ans;
    cin>>n>>k;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ans=bookAllocate(arr,n,k);
    cout<<ans<<endl;
}

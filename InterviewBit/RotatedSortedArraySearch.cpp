//To search for a number in a sorted array which is rotated about a pivot element.
//Example: 4 5 6 7 0 1 2 3 


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int bsearch(vector<int>&vec, int low, int high, int num){
    int mid;
    while(low<=high){
        mid = (low+high)/2;
        if(vec[mid] < num){
            low = mid+1;
        }
        else if(vec[mid] > num){
            high = mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int solve(vector<int>&vec, int b){
    int low = 0;
    int high = vec.size()-1;
    int mid,pivot;
    int temp = vec[0];
    while(low <= high){
        mid = (low + high)/2;
        if(vec[mid] < temp){
            if(vec[mid-1]>temp){
                pivot = mid;
                break;
            }
            else{
                high = mid-1;
            }
        }
        else{
            low = mid+1;
        }
    }
    if(b <= vec[pivot-1] && b >= temp){
        low = 0;
        high = pivot-1;
        int ans = bsearch(vec,low,high,b);
        return ans;
    }
    else if(b >= vec[pivot]){
        low = pivot;
        high = vec.size()-1;
        int ans = bsearch(vec,low,high,b);
        return ans;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> vec;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        vec.push_back(temp);
    }
    int b;
    cin>>b;
    cout<<solve(vec,b)<<'\n';
}

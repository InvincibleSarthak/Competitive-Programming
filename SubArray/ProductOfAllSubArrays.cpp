//{10,3,7}
//Output: 10*(10*3)*(10*3*7)*3*(3*7)*7

#include<iostream>
using namespace std;
void solve(int *arr, int n, long long int &result){
    for(int i=0;i<n;i++){
        long long int product = 1;
        for(int j=i;j<n;j++){
            product = product*arr[j];
            result = result*product;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long int result = 1;
    solve(arr,n,result);
    cout<<result<<'\n';
}

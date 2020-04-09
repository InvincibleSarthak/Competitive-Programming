#include<iostream>
using namespace std;
int solve(int* nums, int n){
  int temp = nums[0]; 
  int result = nums[0];
  for(int i=1;i<n;i++){
    temp = max(nums[i],temp+nums[i]); //If the current number (nums[i]) increases the earlier temp, include it into the sub-array, else, start new sub-array..
    result = max(temp,result); //If the current best is better than the overall best, modify the overall best to current best.
  }
  return result;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
      cin>>nums[i];
    }
    cout<<solve(nums,n)<<'\n';
  }
  return 0;
}

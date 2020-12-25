/*
In Coding blocks test Kartik bhaiya gave students an array of n non-negative integers a1, a2, …, an ,where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). The task is to find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container. 
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int left = 0, right = n-1;
  int area = INT_MIN;
  while(left<=right){
    area = max(area,min(arr[left],arr[right])*(right-left));
    if(arr[left]<arr[right]){
      left++;
    }
    else{
      right--;
    }
  }
  cout<<area<<'\n';
}

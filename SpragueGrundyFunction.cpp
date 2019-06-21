#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll calculateMex(unordered_set<ll> Set){
  ll mex=0;
  while(Set.find(mex)!=Set.end()){
    mex++;
  }
  return(mex);
}
ll calculateGrundy(ll n){
  if(n==0){
    return 0;
  }
  unordered_set<ll> Set;
  for(ll i=1;i<=n;i++){
    Set.insert(calculateGrundy(n-i));
  }
  return (calculateMex(Set));
}

int main(){
  // Just the functions for calculating Grundy Number and Mex(Minimum Non Negative number excluded from the set).

  return 0;
}

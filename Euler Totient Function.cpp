/*In number theory, the totient φ of a positive integer n is defined to be the number of positive integers less than or equal to n that are coprime to n.

Given an integer n (1 <= n <= 10^6). Compute the value of the totient φ.
Input

First line contains an integer T, the number of test cases. (T <= 20000)

T following lines, each contains an integer n.
Output

T lines, one for the result of each test case.*/



#include <iostream>
using namespace std;
#define ll long long
const ll N=1000002;
ll arr[N];
int main() {
	for (ll i=0;i<=N;i++){
	    arr[i]=i;
	}
	for(ll i=2;i<N;i++){
	    if(arr[i]==i){
	        arr[i]-=1;
	        for(ll j=2*i;j<N;j+=i){
	            arr[j]*=(i-1);
                arr[j]/=i;
	        }
	    }
	}
	ll t;
	ll n;
	cin>>t;
	while(t--){
	    cin>>n;
	    cout<<arr[n]<<endl;
	}
	return 0;
}

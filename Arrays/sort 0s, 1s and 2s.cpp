#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    
	    int start = 0, mid = 0, end = n;
	    for(int i=0;i<n;i++){
	        if(arr[i] == 0){
	            start++;
	            mid++;
	        }
	        if(arr[i] == 2){
	            end--;
	        }
	    }
	    for(int i=0;i<start;i++){
	        cout<<0<<' ';
	    }
	    for(int i=mid;i<end;i++){
	        cout<<1<<' ';
	    }
	    for(int i=end;i<n;i++){
	        cout<<2<<' ';
	    }
	    cout<<'\n';
	}
	return 0;
}

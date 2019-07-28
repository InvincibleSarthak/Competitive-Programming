//MaxProfit Wine Problem
//Top-Down Approach



#include<iostream>
#include<cstring>
using namespace std;
int memo[1000][1000];
int maxProfit(int *arr,int start, int end, int year){
    if(start>end) return 0;
    if(memo[start][end] != -1) return memo[start][end];
    int q1 = arr[start]*year + maxProfit(arr,start+1,end,year+1);
    int q2 = arr[end]*year + maxProfit(arr,start,end-1,year+1);
    int ans = max(q1,q2);
    memo[start][end] = ans;
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=0;
    memset(memo,-1,sizeof(memo));
    ans = maxProfit(arr,0,n-1,1);
    cout<<ans<<endl;
}



/*Input
5
2 3 5 1 4

Output
50
*/

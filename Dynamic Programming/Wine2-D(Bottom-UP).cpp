//Wine problem using pure dp approach (bottom-up)

#include<iostream>
using namespace std;
int dp[100][100];
int maxProfit(int *arr, int n){
    int year = n;
    for(int i=0;i<n;i++){
        dp[i][i]=arr[i]*year;
    }
    year--;
    for(int len =2;len<=n;len++){
        int start = 0;
        int end = n - len;
        while(start<=end){
            int endWindow = start + len -1;
            dp[start][endWindow] = max ((arr[start]*year + dp[start+1][endWindow]),(arr[endWindow]*year + dp[start][endWindow-1]));
            start++;
        }
        year--;
    }
    return dp[0][n-1];
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxProfit(arr,n);
}

/*Input
5
2 3 5 1 4

Output
50
*/

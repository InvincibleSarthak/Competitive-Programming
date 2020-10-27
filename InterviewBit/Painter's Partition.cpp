/* 
1. Calculate the maximum possible time.
2. Now, using binary search find the time limit within 1....sum in which all the tasks can be completed with the help of A painters.
3. Finally we get the units, now multiply these units with time per unit B to get the total time taken.
*/


bool check(int A, vector<int>&C, long long int mid){
    int n = C.size();
    long long int sum = 0;
    int painter = 1;
    for(int i=0;i<n;i++){
        if(C[i] > mid)  return false;
        else if(sum + C[i] > mid){
            painter++;
            if(painter > A) return false;
            else    sum = C[i];
        }
        else    sum += C[i];
    }
    return true;
}
int Solution::paint(int A, int B, vector<int> &C)
{
    int n = C.size();
    long long int sum = 0;
    for(int i=0;i<n;i++){
        sum += C[i];
    }
    long long int start = 0, end = sum;
    while(start <= end){
        long long int mid = ((end-start)>>1) + start;
        if(check(A,C,mid))  end = mid-1;
        else    start = mid+1;
    }
    return (start*B)%10000003;
}

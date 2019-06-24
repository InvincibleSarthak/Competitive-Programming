//function1

void bubbleSort(int arr[], int n){
  //base case
  if(n==1){
    return;
  }
  
  //recursive case
  for(int j=0;j<=n-2;j++){
    if(arr[j]>arr[j+1]){
      swap(arr[j],arr[j+1]);
    }
  }
  bubbleSort(arr,n-1);
}


//function2

void bubbleSort2(int arr[],int j, int n){
  //base cases
  if(n==1){
    return;
  }
  if(j==n-1){
    bubbleSort2(arr,0,n-1)
  }
  
  //recursive case
  if(arr[j]>arr[j+1]){
    swap(arr[j],arr[j+1]);
  }
  bubbleSort2(arr,j+1,n);
}

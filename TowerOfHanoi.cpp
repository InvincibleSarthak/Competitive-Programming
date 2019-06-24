//Tower of Hanoi Problem using recursion

void towerOfHanoi(int n,char current, char middle, char destination){
  if(n==0){
    return;
  }
  towerOfHanoi(n-1,current,destination,middle);
  cout<<"Move "<<n<<" from "<<current<<" to "<<destination<<endl;
  towerOfHanoi(n-1,middle,current,destination);
}

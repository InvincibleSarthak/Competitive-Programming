//Subsequences are not necessarily contigous. They can be discontinous as well.
//This code involves printing all the possible subsets of a string including phi ""

#include<iostream>
#include<cstring>
using namespace std;
void filterChars(char *a, int no){
    int i=0;
    while(no>0){
        if(no&1){
            cout<<a[i]<<' ';
        }
        i++;
        no=no>>1;
    }
    cout<<endl;
}
void generateSubsets(char *a){
    int n=strlen(a);
    int range = (1<<n)-1;
    for(int i=0;i<=range;i++){
        filterChars(a,i);
    }
}
int main(){
    char a[1000];
    cin>>a;
    generateSubsets(a);
}

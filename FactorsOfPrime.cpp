//Code to print number of numbers divisible by prime numbers less than 20 till a number n


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector <int> vec;
int main() {
	int n,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
        vec.push_back(0);
        vec.push_back(0);
        for(int i=2;i<=a;i++){
            vec.push_back(1);
        }
		int l=0;
		for(int k=2;k<=19;k=k+2){
            if(k==4){
                k=k-1;
            }
			for(int j=k;j<=a;j+=k){
				if(vec[j]==1){
					l++;
					vec[j]=0;
                }
			}
    	}
        cout<<l<<endl;
        vec.clear();	
	}
	return 0;
}

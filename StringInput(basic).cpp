//This file contains three methods to initialize/define a string.

#include <iostream>
#include<cstring>
using namespace std;
int main() {
    string s("Hello World");
    cout<<s<<endl;
    string s2="Hello World";
    cout<<s2<<endl;
    string s3;
//     Stops taking input when encounters '\n'
    getline(cin,s3);
    cout<<s3<<endl;
    string s4;
//     Stops taking input when encounters a space
    cin>>s4;
    cout<<s4;
}

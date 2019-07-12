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
    getline(cin,s3);
    cout<<s3<<endl;
}

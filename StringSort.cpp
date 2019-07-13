//This code includes the concept of custom comparator. Using it we can sort our vector in the way we want.
//Here the custom comparator will print the result in lexicographical until a substring of a string occurs,
//in that case the string is going to be printed first and then the substring.

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
bool comp(string a, string b){
    if(a[0]==b[0]){
        int k=1;
        if(a.length()>b.length())
        {
            for(int i=0;i<b.length();i++){
                if(a[i]==b[i])
                    k++;
            }
            if(k==b.length()){
                return b>a;
            }
        }
        else    
            return a<b;
    }
    else{
        return b>a;
    }
}
vector<string>vec;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vec.push_back(s);
    }
    sort(vec.begin(),vec.end(),comp);
    for(auto it:vec){
        cout<<it<<endl;
    }
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//template <class A,class B> Function Type: A, Data Type: B
template < class ForwardIterator, class T> 
ForwardIterator search (ForwardIterator start, ForwardIterator end, T key){
    //linear search
    while(start != end){
        if(*start == key){
            return start;
        }
        start++;
    }
    return end;
}
int main() {
    list <int >l;
    l.push_back(1);
    l.push_back(3);
    l.push_back(7);
    l.push_back(5);
    auto it = search(l.begin(),l.end(),5);
    if(it == l.end()){
        cout<<"Element Not Found.";
    }
    else{
        cout<<*it<<endl;
    }

}

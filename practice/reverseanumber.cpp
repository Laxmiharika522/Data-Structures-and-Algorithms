#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int reverse=0;
    while(n>0){
        int k=n%10;
        reverse=reverse*10+k;
        n=n/10;
    }
    cout<<reverse;
}
#include<iostream>
using namespace std;
void printpattern(int n){
    for(int i=n;i>0;i--){
        for(int j=0;j<(n-i);j++){
            cout<<" ";
        }
        for(int j=0;j<(2*i-1);j++){
            cout<<"*";
        }
        
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    printpattern(n);
}
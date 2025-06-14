#include<iostream>
using namespace std;
void printupperpattern(int n){
    for(int i=0;i<n;i++){//upto 5rows
        //stars
        for(int j=0;j<=i;j++){
            cout<<'*';
        }
        //spaces
        for(int j=0;j<2*(n-i-1);j++){
            cout<<" ";
        }
        //stars
        for(int j=0;j<=i;j++){
            cout<<'*';
        }
        cout<<endl;
    }
}
void printlowerpattern(int n){//remaining 4rows
    for(int i=0;i<n-1;i++){
        //stars
        for(int j=0;j<n-1-i;j++){
            cout<<'*';
        }
        //spaces
        for(int j=0;j<2*(i+1);j++){
            cout<<" ";
        }
        //stars
        for(int j=0;j<n-1-i;j++){
            cout<<'*';
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    printupperpattern(n);
    printlowerpattern(n);
}
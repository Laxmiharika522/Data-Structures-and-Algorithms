#include<iostream>
using namespace std;
void printupperpattern(int n){
    for(int i=0;i<n;i++){
        //stars
        for(int j=n;j>i;j--){
            cout<<'*';
        }
        //spaces
        for(int j=0;j<(2*i);j++){
            cout<<" ";
        }
        //stars
        for(int j=n;j>i;j--){
            cout<<'*';
        }
        cout<<endl;
    }
}
void printlowerpattern(int n){
    for(int i=0;i<n;i++){
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

int main(){
    int n;
    cin>>n;
    printupperpattern(n);
    printlowerpattern(n);
}
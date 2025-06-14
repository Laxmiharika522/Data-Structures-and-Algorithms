#include<iostream>
using namespace std;
void printpattern(int n){
    int spaces=2*(n-1);
    for(int i=0;i<n;i++){
        //numbers
        for(int j=0;j<=i;j++){
            cout<<j+1;
        }
        //spaces
        for(int j=0;j<spaces;j++){
            cout<<" ";
        }
        //numbers
         for(int j=i;j>=0;j--){
            cout<<j+1;
        }
        spaces=spaces-2;
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    printpattern(n);
}
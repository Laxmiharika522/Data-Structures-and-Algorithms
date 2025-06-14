#include<iostream>
using namespace std;
void printpattern(int n){
    for(int i=0;i<n;i++){//rows are same only coloumns changes 
        for(int j=n;j>i;j--){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    printpattern(n);
}
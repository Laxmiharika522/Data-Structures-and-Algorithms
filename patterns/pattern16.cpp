#include<iostream>
using namespace std;
void printpattern(int n){
    char start='A';
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<start<<" ";
        }
        start++;
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    printpattern(n);
}
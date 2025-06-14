#include<iostream>
using namespace std;
void printpattern(int n){
    for(int i=0;i<n;i++){
        for(char j='A';j<='A'+i;j++){//char pattern
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    printpattern(n);
}
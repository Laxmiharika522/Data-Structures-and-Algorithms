#include<iostream>
using namespace std;
void printpattern(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=n-i-1;j++){
            cout<<" ";
        }
        if(i==0){
            for(char j='A';j<='A'+i;j++){
            cout<<j;
        }
        }
        else{
            for(char j='A';j<='A'+i;j++){
            cout<<j;
        }
            for(char j='A'+i-1;j>='A';j--){
            cout<<j;
            }
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    printpattern(n);
}
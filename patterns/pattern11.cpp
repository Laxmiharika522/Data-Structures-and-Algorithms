#include<iostream>
using namespace std;
void printpattern(int n){
    for(int i=0;i<n;i++){
        int start=0;
        if(i%2==0){
            start=1;
        }
        for(int j=0;j<=i;j++){
            cout<<start<<" ";
            start=1-start;//to get alternate 0 or 1    
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    printpattern(n);
}
////Time complexity O(sqrt(n))
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k=0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            k=1;
        }
    }
    if(k==0){
        cout<<"prime";
    }else{
        cout<<"not a prime";
    }
}
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x=n;
    int y=n;
    int sum=0;
    int length=0;
    while(n>0){
        n=n/10;
        length++;
    }
    while(x>0){
        int k=x%10;
        sum+=pow(k,length);
        x=x/10;
    }
    if(y==sum){
        cout<<"true";
    }
    else{
        cout<<"false";
    }

}
#include<iostream>
using namespace std;
void gcd(int n,int m){
    while(n>0){
        int k=m%n;
        int temp=n;
        n=k;
        m=temp;
    }
    cout<<m;

}
int main(){
    int n,m;
    cin>>n>>m;
    gcd(n,m);
}
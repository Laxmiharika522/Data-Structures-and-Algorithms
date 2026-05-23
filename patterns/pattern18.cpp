#include<iostream>
using namespace std;
void printpattern(int n){
    for(int i=0;i<n;i++){
        // Assuming the pattern should scale with n, printing characters up to 'A' + n - 1
        // If the intention is to always end at 'E', then n should be <= 5.
        char start_char = 'A' + (n - 1) - i;
        char end_char = 'A' + (n - 1);
        for(char j=start_char; j<=end_char; j++){
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
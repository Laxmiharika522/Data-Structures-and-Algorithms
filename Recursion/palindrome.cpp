//int n = strlen(s);  // ❌ Wrong: `strlen()` works only with C-style strings (`char[]`), not C++ `string`.
#include<iostream>
using namespace std;
bool palindrome(string s,int i){
    int n=s.length(); //s.length() for strings . strlen() for charecter arrays
    if(i>=n/2){
        return true;
    }if(s[i]!=s[n-i-1]){
        return false;
    }
    return palindrome(s,i+1);
}
int main(){
    string s;
    cin>>s;
    //cout<<palindrome(s,0); gives output zero or 1
    if(palindrome(s,0)){
        cout<<"Palindrome";
    }else{
        cout<<"Not a palindrome";
    }

}
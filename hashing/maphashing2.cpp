#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    string s;
    cin>>s;
    //pre compute
   unordered_map<char,int>mpp;
    for(int i=0;i<s.size();i++){
        mpp[s[i]]++;
    }
    int n;
    cin>>n;//number of inputs or queries
    while(n--){
        char c;
        cin>>c;
        //fetech
        cout<<mpp[c]<<endl;
        
    }
}
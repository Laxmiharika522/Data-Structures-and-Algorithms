#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    //pre compute
    int hash[26]={0};//if there are only small letters
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }
    int n;
    cin>>n;//number of inputs or queries
    while(n--){
        char c;
        cin>>c;
        //fetech
        cout<<hash[c-'a']<<endl;
    }
}

//for both uppercase and lowercase charecters
/*#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    //pre compute
    //hash is just a name u can give arr also
    int arr[256]={0};//if there are only small letters
    for(int i=0;i<s.size();i++){
        arr[s[i]]++; //auto matically s[i] converted to integer
    }
    int n;
    cin>>n;//number of inputs or queries
    while(n--){
        char c;
        cin>>c;
        //fetech
        cout<<arr[c]<<endl; //automatically c is converted into integer(ascii)
    }
}*/

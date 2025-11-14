//TC------>O(3N) + O(K)
//SC------>O(N)[Stack] + O(N)[store the element in string]
#include<iostream>
#include<string>
#include<stack>
using namespace std;
string function(string str,int k){
    int n = str.size();
//     s.size() == s.length()
//     No difference in performance or meaning.
    stack<char>st;
    for(int i=0;i<n;i++){ //O(N)
        while(!st.empty() && k>0 && (st.top()-'0')>(str[i]-'0')){
            st.pop();
            k=k-1;
        }
        st.push(str[i]);    
    }
    while(k>0){//still the value of k is not zero //O(K)
        st.pop();
        k--;
    }
    if(st.empty()){//if stack is empty return 0
        return "0";
    }
    string res = "";
    while(!st.empty()){//O(N) for reversing
        res = st.top() + res ; //to reverse the string
        st.pop();
    }
    int i=0;
    while(i<res.size() && res[i]=='0'){ //O(N) to remove trailing zeroes
        i++;
    }
    res = res.substr(i); //s = helloworld cout << s.substr(5) << endl;     // "World" (from index 5 till end)
    return res.empty() ? "0" : res;
} 
int main(){
    string str;
    cin>>str;
    int k;
    cin>>k;
    string result = function(str,k);
    cout<<result;
}
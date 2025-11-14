//Asteroidal colision
//Without considering reverse
//TC----> O(N) + O(N)[for entire while loop]
//SC-----> O(N)(Stack to store elements) 
#include<iostream>
#include<stack>
using namespace std;
void function(int arr[],int n){
    stack<int>st;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            st.push(arr[i]);
        }else{
            while(!st.empty() && st.top()>0 && st.top()<abs(arr[i])){
                st.pop();
            }
            if(!st.empty() && st.top() == abs(arr[i])){
                st.pop();
            }else if(st.empty() || st.top()<0){//no collision when stack is empty and stack contains already negative elements they are is same direction so no collision
                st.push(arr[i]);
            }
        }
    }
    int reversed[n];
    int i=0;
    while (!st.empty()) {//we need to get in reverse order because 1st element is stored in bottom of the stack
        reversed[i] = st.top();  // access top element
        st.pop();    // remove top
        i++;             
    }
    for(int j=i-1;j>=0;j--){
        cout<<reversed[j]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    function(arr,n);
}
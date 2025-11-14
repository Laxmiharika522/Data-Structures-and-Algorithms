//Maximal Rectangle all input contains 0's or 1's
//TC----->O(N*M)[prefix sum calculation] + O(N*2M)
//SC------>O(N*M) + O(N)[stack]
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int maximumArea(vector<int>&arr,int n){//O(2M) Were M is number of elements in each row
    stack<int>st;
    int maxArea =0;
    int nse;
    int pse;
    int elementidx;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            elementidx = st.top();
            st.pop(); //at maximum we can pop N elements in the entire program if stack stores N elements
            nse =i;
            pse = st.empty()?-1:st.top();
            maxArea = max(maxArea,(nse-pse-1)*arr[elementidx]);
        }
        st.push(i); //we are pushing indexes
    }
    while(!st.empty()){
        nse = n;
        elementidx = st.top();
        st.pop();//this pop is also included in previous while only 
        pse = st.empty()?-1:st.top();
        maxArea = max(maxArea,(nse-pse-1)*arr[elementidx]);
    }
    return maxArea;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    vector<vector<int>> prefix(n,vector<int>(m));
    int maxarea =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int j=0;j<m;j++){
        int sum =0;
        for(int i=0;i<n;i++){
            sum+=arr[i][j];
            if(arr[i][j]==0){
                sum= 0;
            }
            prefix[i][j] = sum;
        }
    }
    for(int i=0;i<n;i++){
        maxarea = max(maxarea,maximumArea(prefix[i],m));//each row contains m elements
    }
    cout<<maxarea;
}
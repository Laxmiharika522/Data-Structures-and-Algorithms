//print the matrix in spiral fashion
//Tc------> O(N*M) //we are travelling all the elements
//SC-------> O(N*M) //Storing all elements in vector

#include<iostream>
#include<vector>
using namespace std;
vector<int> spiral(vector<vector<int>>arr){
    int n= arr.size();
    int m= arr[0].size();
    int left =0,right = m-1;
    int top = 0,bottom = n-1;
    vector<int>ans;//O(N*M)
    while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++){
            ans.push_back(arr[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(arr[i][right]);
        }
        right--;
        if(top<=bottom){//dont know this condition why
            for(int i=right;i>=left;i--){
            ans.push_back(arr[bottom][i]);
        }
        bottom--;
        }
        if(left<=bottom){
            for(int i=bottom;i>=top;i--){
            ans.push_back(arr[i][left]);
        }
        left++;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    vector<int>result = spiral(arr);
    for(int i=0;i<result.size();i++){
            cout<<result[i]<<" ";
    }
}
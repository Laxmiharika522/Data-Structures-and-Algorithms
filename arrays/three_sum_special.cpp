#include<iostream>
#include<set>
#include<Algorithm>
#include<vector>
using namespace std;
vector<vector<int>> three_sum(int arr[],int n){
   set<vector<int>>st;
   for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    if(arr[i] != arr[j] && arr[j] != arr[k] && arr[i] != arr[k]){
                        //all the elements in set should be unique and no duplicate triplets like [1,-1,0] [0,1,-1] [1,0,-1]
                        vector<int>temp = {arr[i],arr[j],arr[k]};//only three elements
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i]; // 
    }
    vector<vector<int>>result = three_sum(arr,n);
    //for each loop
   for(vector<int>triplet : result){
        for(int val:triplet){
            cout<<val<<" ";
        }
        cout<<endl;
   }
}
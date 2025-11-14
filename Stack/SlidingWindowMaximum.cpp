//bruete
//Time complexity ---->O(N-K)*O(K)
//space complexity ----->O(N-K)
#include<iostream>
#include<vector>
using namespace std;
vector<int> SlidingWindow(int arr[],int k,int n){
    vector<int>res;
    for(int i=0;i<=n-k;i++){
        int maxi = arr[i];
        for(int j=i;j<=i+k-1;j++){
            maxi = max(maxi,arr[j]);
        }
        res.push_back(maxi);
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    vector<int>result = SlidingWindow(arr,k,n);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}

//Optimal

//Find the maximum profit after selling the stock
//TC----->O(N)
//SC------>O(1)
#include<iostream>
using namespace std;
int buy_and_sell(int arr[],int n){
    int mini=arr[0];
    int max_profit=0;
    for(int i=0;i<n;i++){
        int cost=arr[i]-mini;
        max_profit=max(max_profit,cost);
        mini=min(mini,arr[i]);
    }
    return max_profit;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<buy_and_sell(arr,n);
}
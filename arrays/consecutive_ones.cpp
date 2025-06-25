#include<iostream>
using namespace std;
int consecutive_ones(int arr[],int n){
    int max1=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
            max1=max(max1,count);
        }
        else{//if arr[i]==0
            count=0;
        }
    }
    return max1;
}
int main(){
    int n;
    cin>>n;
    int arr[n-1];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    cout<<consecutive_ones(arr,n);
}
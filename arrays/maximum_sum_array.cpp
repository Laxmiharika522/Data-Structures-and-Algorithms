//doubt
//kadane's algorithm
#include<iostream>
using namespace std;
void max_sum_array(int arr[],int n){
    int sum=0;
    int maxi=INT_MIN;
    int start=0,ansstart=0,ansend=0;
    for(int i=0;i<n;i++){
        if(sum==0){
            start=i;
        }
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
            ansstart=start;
            ansend=i;
        }
        if(sum<0){
            sum=0;
        }
    }
    for(int i=0;i<n;i++){
        if(i>=ansstart && i<=ansend){
            cout<<arr[i]<<" ";
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    max_sum_array(arr,n);
}
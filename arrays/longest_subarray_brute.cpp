//Find the longest subarray with sum k
//bruete
//TC-------> O(n^3) but in brute force approach only we can reduce to O(n^2)
#include<iostream>
using namespace std;
int subarray(int arr[],int n,int x){
    int longest_length=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];  
            }
            if(sum==x){//out side the third loop because 2 loop runs every time
                longest_length=max(longest_length,j-i+1);
            }
        }
    }
    return longest_length;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    cout<<subarray(arr,n,x);
}*/


//bruete
//TC---->O(n^2)
/*#include<iostream>
using namespace std;
int subarray(int arr[],int n,int x){
    int longest_length=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==x){
                longest_length=max(longest_length,j-i+1);
            }
        }
    }
    return longest_length;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    cout<<subarray(arr,n,x);
}*/

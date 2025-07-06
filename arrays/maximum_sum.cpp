//to find the subarray which gives maximu sum
//bruete
//TC---->O(N^3)
//SC----->O(1)
#include<iostream>
using namespace std;
int max_sum(int arr[],int n){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            //all possible subarrays
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            if(sum>maxi){
                maxi=sum;
            }
        }
    }
    return maxi;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<max_sum(arr,n);
}


//better
//TC----->O(N^2)
//SC------>O(1)
/*#include<iostream>
using namespace std;
int max_sum(int arr[],int n){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            maxi=max(sum,maxi);
        }

    }
    return maxi;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<max_sum(arr,n);
}*/


//optimal ------->Kadane's Algorithm(if sum is less than zero make it zero)
//TC---->O(n)
//sc---->O(1)
/*#include<iostream>
using namespace std;
int max_sum(int arr[],int n){
    int sum=0;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<max_sum(arr,n);
}*/

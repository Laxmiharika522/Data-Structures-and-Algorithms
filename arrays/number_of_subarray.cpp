//Count the subarrays sum Equals k
//Tc----->O(N^3)
#include<iostream>
using namespace std;
int sub_arrays(int arr[],int n,int k){
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];//taking each and every subarray
            }
            if(sum==k){
                count++;
            }
        }
    }
    return count;
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
    cout<<sub_arrays(arr,n,k);
}


//better
//TC---->O(N^2)
/*#include<iostream>
using namespace std;
int sub_arrays(int arr[],int n,int k){
    int count = 0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j]; //adding each and every element and checking
            if(sum==k){
                count++;
            }
        }
    }
    return count;
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
    cout<<sub_arrays(arr,n,k);
}*/


//optimal
//Tc----> O(N*LOGN)(genarally) or O(N) or O(N*N) based on unordrer map
//SC---->O(N) //assuming map stores all the data from the array
/*#include<iostream>
#include<unordered_map>
using namespace std;
int sub_arrays(int arr[],int n,int k){
    unordered_map<int,int>mpp;
    mpp[0] =1;
    int presum =0,cnt=0;
    for(int i=0;i<n;i++){
        presum+=arr[i];
        int remove = presum - k;
        cnt+=mpp[remove];
        mpp[presum]+=1;
    }
    return cnt;
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
    cout<<sub_arrays(arr,n,k);
}*/
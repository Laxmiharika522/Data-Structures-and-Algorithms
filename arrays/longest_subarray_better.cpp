//better //hashing
//this method is used if there are negatives and positives in array 
//for negatives in array this is the optimal approach
//if there are only positives in an array this is better solution

//TC---->O(N*LOGN)//ordered map  ; O(N*1)// unorderd map in best case   ;O(n*n)//unorderd map in worst case
//SC----->O(N)//in worst case all the prefix sum stored in map

#include<iostream>
#include<map>
using namespace std;
int subarray(int arr[],int n,int x){
    map<long long int,int>presummap;
    long long sum=0;
    int max_length=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==x){
            max_length=max(max_length,i+1);
        }
        int rem=sum-x;

        //if that rem exists in map then there are certain elements whose sum is x
        //we can find that elements by using i-presummap[rem]

        if(presummap.find(rem)!=presummap.end()){
            int len=i-presummap[rem];
            max_length=max(max_length,len);
        }

        //adding in map 
        //if sum of elements does not exist in map we are adding sum and its index in map
        if(presummap.find(sum)==presummap.end()){
            presummap[sum]=i;
        }
    }
    return max_length;
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
}


//Find the number that appears ones and other numbers appears twice
//Note: other numbers defenately appears twice
//brute
//TC---->O(N*N)
//SC----->O(1)
#include<iostream>
using namespace std;
int appears_ones(int arr[],int n){
    for(int i=0;i<n;i++){
        int num=arr[i];
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[j]==num){
                count++;
            }
        }
        if(count==1){
            return num;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<appears_ones(arr,n);
}

//better
//TC---->O(3N)
//SC----->O(K+1) where is k is maximum element
/*#include<iostream>
using namespace std;
int appears_ones(int arr[],int n){
    int maxi=arr[0];
    for(int i=0;i<n;i++){//O(N)
        if(arr[i]>maxi){
            maxi=arr[i];
        }
    }
    int hash[maxi+1]={0};
    for(int i=0;i<n;i++){//O(N)
        hash[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        if(hash[arr[i]]==1){//O(N)
            return arr[i];
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<appears_ones(arr,n);
}*/


//If the maximum element is very large we cant we use hash array we use map
//ex: 5 10000 10000 100 100 1000000
//o/p: 1000000
//TC------>O(NLOGM)+O(N/2+1)
//SC----->O(N/2+1)
/*#include<iostream>
#include<map>
using namespace std;
int appears_ones(int arr[],int n){
    map<long long int,int>mpp;//O(LOGM) WHERE M IS SIZE OF MAP
    for(int i=0;i<n;i++){//O(NLOGM)
        mpp[arr[i]]++;//if arr[i] is very large ex: 10^12....
    }
    for(auto it:mpp){//O(N/2+1) because every element repeats twice except one element
        if(it.second==1){
            return it.first;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<appears_ones(arr,n);
}*/

//optimal - xor operation since every element repeats twice
//TC------>O(N)
//SC------>O(1)
/*#include<iostream>
using namespace std;
int appears_ones(int arr[],int n){
    int xor1=0;
    for(int i=0;i<n;i++){
        xor1^=arr[i];
    }
    return xor1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<appears_ones(arr,n);
}*/
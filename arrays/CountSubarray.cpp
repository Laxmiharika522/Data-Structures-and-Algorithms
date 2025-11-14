//count the subarray with xor as m
//TC---->O(n^3)
//sc--->O(1)
//brute
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    int count =0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int xr=0;
            for(int k=i;k<=j;k++){
                xr = xr^arr[k];
            }
            if(xr==m){
                count++;
            }
        }
    }
    cout<<count;
}

//better 
//TC---->O(N^2)
//SC--->O(1)
/*#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int count =0;
    for(int i=0;i<n;i++){
        int xr=0;
        for(int j=i;j<n;j++){
            xr = xr ^ arr[j];
            if(xr==k){
                count++;
            }
        }
    }
    cout<<count;
}*/

//Optimal
//TC---->O(N) OR O(NLOGN) depending on type of map used
//SC---->O(N) for map. A max it stores N elements
/*#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    int count =0;
    int xr =0;
    map<int,int>mpp;
    mpp[xr]++; //store first element {0,1}
    for(int i=0;i<n;i++){
        xr = xr^arr[i];
        int x = xr^m;
        count += mpp[x];
        mpp[x]++;
    }
    cout<<count;    
}*/
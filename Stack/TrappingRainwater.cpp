//breute force approach
// #include<iostream>
// using namespace std;
// int prefixMax[100];
// int suffixMax[100];
// void calculate(int arr[],int n){
//     prefixMax[0] = arr[0];
//     for(int i=1;i<n;i++){
//         prefixMax[i] = max(prefixMax[i-1],arr[i]);
//     }
//     suffixMax[n-1] = arr[n-1];
//     for(int i = n-2;i>=0;i--){
//         suffixMax[i] = max(suffixMax[i+1],arr[i]);
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int total =0;
//     calculate(arr,n);
//     for(int i=0;i<n;i++){
        //we calculate prefixMax and suffixMax because if you pick one particular builder we can store water when buildings on the right and buiding on the left should be greater
//         if(arr[i]<prefixMax[i] && arr[i]<suffixMax[i]){
//             total+=(min(prefixMax[i],suffixMax[i]) - arr[i]);
//         }
//     }
//     cout<<total;
// }

//while comparing left and and right check for smaller building.
//at the same time with respect to that particular building left and right buildings should be greater
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int lmax=0;int rmax= 0;int total=0;
    int l =0;
    int r = n-1;
    while(l<r){
        if(arr[l]<=arr[r]){//amount of storage depends on smaller building
            if(lmax>arr[l]){//building on the left is taller
                total+=lmax-arr[l];
            }else{
                lmax = arr[l];
            }
            l++;
        }else{
            if(rmax>arr[r]){//building on the right should be taller
                total+=rmax-arr[r];
            }else{
                rmax = arr[r];
            }
            r--;
        }
    }
    cout<<total;
}
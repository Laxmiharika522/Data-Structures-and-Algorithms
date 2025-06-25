//pushes the maximum element to the last by adjacent swaps
//Time complexity of worst and average situation is O(n^2)
#include<iostream>
using namespace std;
void bubble_sort(int arr[],int n){
    for(int i=n-1;i>=1;i--){//if we give i==0 then j<=-1 which will not execute
        for(int j=0;j<=i-1;j++){//since we are taking j+1 so j<=i-1 which is equal to j<=n-2 
        //now we need to compare arr[n-2] and arr[n-2+1] .
        //if we dont give i-1 then we have to compare arr[n-1] and arr[n-1+1]{which does no exist}
        if(arr[j]>arr[j+1]){
            int temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
        }
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
    bubble_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}

//for the best case O(n)
//if the given array is already sorted then there are no swaps
/*#include<iostream>
using namespace std;
void bubble_sort(int arr[],int n){
    for(int i=n-1;i>=1;i--){
        int swap=0;
        for(int j=0;j<=i-1;j++){
        if(arr[j]>arr[j+1]){
            int temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
            int swap=1;
        }
        }
        if(swap==0){//if there are no swaps then break it
            break;
        }
        cout<<"breaked";//if the loop is breaked then this line will not execcute otherwise the outer loop runs 5 time then "breaked" prints 5times
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubble_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}*/

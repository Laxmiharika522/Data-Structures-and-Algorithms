//sort the array which contains only 0's,1's,2's
//Note the array should contain 0's ,1's and 2's only
//brute --------> merge sort --------> TC--->O(NLogN)     SC------->O(N)
//better
//TC----->O(N)+O(N)
//SC---->O(1)
#include<iostream>
using namespace std;
void sorting(int arr[],int n){
    int cnt0=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            cnt0++;
        }
        else if(arr[i]==1){
            cnt1++;
        }
        else{
            cnt2++;
        }
    }
    for(int i=0;i<cnt0;i++){
        arr[i]=0;
    }
    for(int i=cnt0;i<cnt0+cnt1;i++){
        arr[i]=1;
    }
    for(int i=cnt0+cnt1;i<n;i++){
        arr[i]=2;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sorting(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}

//Optimal
//Dutch algorithm or 3pointer approach
//TC------>O(N)
//SC------>O(1)
/*#include<iostream>
using namespace std;
void sorting(int arr[],int n){
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++; //after swaping 0 goes to 1 and 1 goes to 0 so we no need to check 1 again 1 is in sorted order so mid++
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
            //no mid++ because if we swaped 2 can be swaped with 1 or 0 . if it is 0 means we need to swap again(to put in sorted order) if it is 1 we no need to swap
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
    sorting(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}*/
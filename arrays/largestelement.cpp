//three approches 
//1) bruete which takes O(NlogN) 
#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>&arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){//equal to because if pivot element and other element are equal then equal elements will stay at left 
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    //if j crosses i then replace picot element with jth element
    swap(arr[low],arr[j]);
    return j;
}
void quick_sort(vector<int>&arr, int low,int high){
    if(low<high){
        int par_index=partition(arr,low,high);
        quick_sort(arr,low,par_index-1);
        quick_sort(arr,par_index+1,high);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>vec;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    //sort the array which takes o(NlogN)
    quick_sort(vec,0,n-1);
    //last element is the largest element
   cout<<vec[n-1];
}


//2) optimal TC--->O(N)
/*#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //assume
    int largest=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    cout<<largest;
}*/
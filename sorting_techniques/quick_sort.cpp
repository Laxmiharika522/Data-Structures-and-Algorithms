//Timecomplexity is O(N*log(base2)N)
//space complexity is O(1) since we arenot  using extra space.Recusrsion stack space is ignored
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
    quick_sort(vec,0,n-1);
    for(auto it:vec){
        cout<<it;
    }
}
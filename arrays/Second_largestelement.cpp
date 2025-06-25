//second_largest is not equal to arr[n-2] consider the case arr[]={1,2,4,7,7,5} after sorting u will get {1,2,4,5,7,7} n-2 is not second largest element
//1)brute TC-------->(NlogN+N)
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
    //since vector is sorted
    int largest=vec[n-1];
    for(int i=n-2;i>=0;i++){//already sorted
        if(vec[i]!=largest){
            cout<<vec[i];
            break;
        }
        else{//in case of {7,7,7,7,7}
            cout<<"-1";
        }
    }
}


//2)better TC-------> O(2N) 
/*#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //O(N)
    int largest=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    //O(N)
    int second_largest=INT_MIN;
    for(int i=0;i<n;i++){//ex: {1,3,7,5,4,7}
        if(arr[i]!=largest && arr[i]>second_largest){
            second_largest=arr[i];//5
        }
    }
    cout<<second_largest;
}*/

//3) optimal TC------>O(N)
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
    int second_largest=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){//if arr[i] becomes largest then largest becomes second_largest
            second_largest=largest;
            largest=arr[i];
        }
        //sometimes arr[i] not greater then largest but it becomes the second largest
        //ex: [1,2,4,7,7,5] 5!>7 but 5 is second_largest
        else if(arr[i]<largest && arr[i]>second_largest){
            second_largest=arr[i];
        }
    }
    cout<<second_largest;
}*/

//count inversions in an array
//we need find i<j and arr[i]>arr[j]
//left element should be greater than right element
//brute force approach
//TC---->O(N^2)
//SC---->O(1)
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int count =0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){//satisfies i<j
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    printf("%d",count);
}

//OPTIMAL using merge sort
//TC--->O(NLOGN)
//SC--->O(N)
/*#include<iostream>
#include<vector>
using namespace std;
int merge(vector<int>&vec,int low,int mid,int high){
    vector<int>temp; //temporary array
    //[low....mid]
    //[mid+1.....high]
    int left=low; //starting index of left half of array
    int right=mid+1; //starting index of right half of an array

    //sorting elements in the temporary array in a sorted manner
    int count =0;
    while(left<=mid && right<=high){
        if(vec[left]<=vec[right]){
            temp.push_back(vec[left]);
            left++;
        }
        //right smaller //if right element is smaller here we will increment the count
        else{
            temp.push_back(vec[right]);
            count +=(mid-left+1);
            right++;
        }
    }
    //there are some elements in the right
    while(left<=mid){
        temp.push_back(vec[left]);
        left++;

    }
    while(right<=high){
        temp.push_back(vec[right]);
        right++;

    }
    for(int i=low;i<=high;i++){
        vec[i]=temp[i-low]; //low-low=0 ; low+1-low=1
    }
    return count;

}
int merge_sort(vector<int>&vec,int low,int high){//we are adding each and every count
    int cnt =0;
    if(low==high){//if there is only one element in an array
        return cnt;
    }
    int mid=(low+high)/2;
    //first half of vector
    cnt+=merge_sort(vec,low,mid);//at one particular point it will reach to return; statement then it will read next statement
    //second half of vector
    cnt+=merge_sort(vec,mid+1,high);
    cnt += merge(vec,low,mid,high);  
    return cnt;  
}
int numberOfInversions(vector<int>&arr,int n){
     return merge_sort(arr,0,n-1);
    
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
    cout<<numberOfInversions(vec,n);
    
}*/
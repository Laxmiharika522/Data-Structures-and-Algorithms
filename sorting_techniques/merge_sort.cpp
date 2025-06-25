//Timecomplexity is O(N*log(base2)N)
//space complexity is O(N) since we are using extra temp variable
#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&vec,int low,int mid,int high){
    vector<int>temp;
    //[low....mid]
    //[mid+1.....high]
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(vec[left]<=vec[right]){
            temp.push_back(vec[left]);
            left++;
        }
        else{
            temp.push_back(vec[right]);
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

}
void merge_sort(vector<int>&vec,int low,int high){
    if(low==high){//if there is only one element in an array
        return;
    }
    int mid=(low+high)/2;
    //first half of vector
    merge_sort(vec,low,mid);//at one particular point it will reach to return; statement then it will read next statement
    //second half of vector
    merge_sort(vec,mid+1,high);
    merge(vec,low,mid,high);    
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
    merge_sort(vec,0,n-1);
    for(auto it:vec){
        cout<<it;
    }
}
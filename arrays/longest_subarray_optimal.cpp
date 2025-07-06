//if the array contains positives and zeroes only this is optimal solution
//TC---->O(2N)//each time when the outer while loop runs inner loop may or may not run N times.Beacuse sometimes it wont satisfy the inner while loop conditions
//SC----->O(1)//no extra space is used 
#include<iostream>
using namespace std;
int subarray(int arr[],int n,int x){
    int left=0,right=0;
    long long sum=arr[0];
    int maxlen=0;
    while(right<n){
        //if sum exceeds x then subract elements from left
        while(left<=right && sum>x){//we cant cross the right if crosses right-left will be negative buut length is always positive
            sum-=arr[left];
            left++;
        }
        //if sum matches then take maximum length
        if(sum==x){
            maxlen=max(maxlen,right-left+1);
        }
        //already sum has arr[0]  so now we need to increment the pointer and add the elements
        right++;
        if(right<n){
            sum+=arr[right];
        }
    }
    return maxlen;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    cout<<subarray(arr,n,x);
}


//Q) rotate the array by left by one place
//ex:arr[]={1,2,3,4,5} o/p: {2,3,4,5,1}
//TC----> O(N)
//what is space occupied in the algorithm is O(N)
//what is extra space occupied in the algorithm is O(1)

//optimal
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

}
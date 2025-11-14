//merge two arrays without using extraspace as optimal approach
//brute force
//TC----> O(N+M)(to put into arr3) + O(N+M)(to put back in arr1 and arr2)
//SC----> O(N+M)
// #include<iostream>
// using namespace std;
// void merge(int arr1[],int arr2[],int n,int m){
//     int arr3[n+m];
//     int left =0;
//     int right =0;
//     int index =0;
//     while(left<n && right<m){
//         if(arr1[left]<=arr2[right]){//if left element is smaller add left element
//             arr3[index] = arr1[left];
//             left++,index++;
//         }
//         else{
//             arr3[index] = arr2[right];
//             right++;index++;
//         }
//     }
//     while(left<n){//there are some elements left in 
//         arr3[index++] = arr1[left++];
//     }
//     while(right<m){//there are some elements on right
//         arr3[index++] = arr2[right++];
//     }
//     for(int i=0;i<n+m;i++){
//         if(i<n){
//             arr1[i] = arr3[i];
//         }else{
//             arr2[i-n] = arr3[i];
//         }
//     }
//     for(int i=0;i<n+m;i++){
//         cout<<arr3[i]<<" ";
//     }

// }
// int main(){
//     int n;
//     cin>>n;
//     int arr1[n];
//     for(int i=0;i<n;i++){
//         cin>>arr1[i];
//     }
//     int m;
//     cin>>m;
//     int arr2[m];
//     for(int i=0;i<m;i++){
//         cin>>arr2[i];
//     }
//     merge(arr1,arr2,n,m);
// }


//optimal
//TC--->O(min(n,m)) + O(nlogn) + O(mlogm){sorting}
//OC----->O(1) we are not using any extra space
#include<iostream>
#include<algorithm>
using namespace std;
void merge(int arr1[],int arr2[],int n,int m){
    int left = n-1;
    int right = 0;
    while(left>=0 && right<m){
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
            left--;right++;
        }else{//the arrays are already sorted so we can break it
            break;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    for(int i=0;i<m;i++){
        cout<<arr2[i]<<" ";
    }

}
int main(){
    int n;
    cin>>n;
    int arr1[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    int m;
    cin>>m;
    int arr2[m];
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    merge(arr1,arr2,n,m);
}

//optimal another method ----> gap method
//TC----->log(n+m) //while loop * O(n+m);
//sc----->O(1) mo extra space;
/*#include<iostream>
using namespace std;
void swapIfGreater(int arr1[],int arr2[],int index1,int index2){
    if(arr1[index1]>arr2[index2]){
        swap(arr1[index1],arr2[index2]);
    }
}
void merge(int arr1[],int arr2[],int n,int m){
    int len = n+m;
    int gap = (len/2) + (len%2); //ceil division
    while(gap>0){
        int left =0;
        int right = left+gap;
        while(right<len){
            if(left<n && right>=n){
                swapIfGreater(arr1,arr2,left,right-n);
            }else if(left>=n){//elements on right array so we need to subtact from n to get actual index
                swapIfGreater(arr2,arr2,left-n,right-n);
            }else{//elements on the left array
                swapIfGreater(arr1,arr1,left,right);
            }
            left++;
            right++;
        }
        if(gap==1){//if second time gap
            break;
        }
        gap = (gap/2) + (gap%2);
    }
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    for(int i=0;i<m;i++){
        cout<<arr2[i]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int arr1[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
        
    int m;
    cin>>m;
    int arr2[m];
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    merge(arr1,arr2,n,m);
}*/
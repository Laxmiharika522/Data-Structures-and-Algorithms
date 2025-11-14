//find the maimum product of subarray is array contains negatives also
//brute- generate all the possible subarrays
//TC--->O(N^2)
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
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int prod =1;
            for(int k =i;k<=j;k++){
                prod = prod*arr[k];
            }
            maxi = max(maxi,prod);
        }
    }
    cout<<maxi;
}

//BETTER
//TC---.o(n^2)
//sc--->O(1)
/*#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int prod =1;
        for(int j=i;j<n;j++){
            prod = prod*arr[j];
            maxi = max(maxi,prod);
        }
    }
    cout<<maxi;
}*/

//OPTIMAL
//TC--->O(N)
//SC--->O(1)
/*#include<iostream>
using namespace std;
int subarryMaxProduct(int arr[],int n){
    int prefix =1;
    int suffix = 1;
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        if(prefix==0){//if you encountered 0 reset to 1
            prefix =1;
        }if(suffix ==0){
            suffix =1;
        }
        //if there is one negative elemnt we need to remove that element hypotetically .so we check prefix of negative element and suffix of negative element for maximum product ignoring that element
        //when we pass through that element product becomes negative so maximum will not effect
        prefix = prefix * arr[i];
        suffix = suffix * arr[n-i-1];
        ans = max(ans,max(prefix,suffix));//everytime we are checking and updating the maximum
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<subarryMaxProduct(arr,n);
}*/
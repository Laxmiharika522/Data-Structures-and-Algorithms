//rearrange the elements in alternate positive and negative elements if array contains equal positives and negatives
//Note: array contains equal positives and negatives
//TC---->O(N)+O(N/2)
//SC----->O(N) For storing positive and negative elements
#include<iostream>
#include<vector>
using namespace std;
void rearrange(int arr[],int n){
    vector<int>pos,neg;
    for(int i=0;i<n;i++){//O(N)
        if(arr[i]>0){
            pos.push_back(arr[i]);
        }else{
            neg.push_back(arr[i]);
        }
    }
    for(int i=0;i<n/2;i++){//O(N/2)
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];
    }

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    rearrange(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

//Optimal
//TC---->O(N)
//SC----->O(N) For answer vector
/*#include<iostream>
#include<vector>
using namespace std;
vector<int> rearrange(vector<int>vec){
    int n=vec.size();
    vector<int>ans(n,0);//initializing vector with n elements and each element is 0
    int posindex=0,negindex=1;
    for(int i=0;i<n;i++){//O(N)
        if(vec[i]>0){
            ans[posindex]=vec[i];
            posindex+=2;//alternating
        }
        else{
            ans[negindex]=vec[i];
            negindex+=2;
        }
    }
    return ans;

}int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    vector<int>ans=rearrange(vec);
    for(auto it:ans){
        cout<<it<<" ";
    }
}*/
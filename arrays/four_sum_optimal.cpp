//TC--->O(N*N)*O(N)(while loop)
//SC----->O(No.of of quards)//only to return the answer
#include<iostream>
#include<Algorithm>
#include<vector>
using namespace std;
vector<vector<int>> three_sum(int arr[],int n){
    vector<vector<int>>ans;
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]){//first time i will be at 0th position only we need to compare with previous element so i>0
            continue;//it will go to next iteration //otherwise you will end taking same triplets
        }
        for(int j=i+1;j<n;j++){
            if(i>i+1 && arr[j]==arr[j-1]){//first time j will be at 1st postion only after that we need to compare with previous element
                continue;
            }  
            int k =j+1;
            int l=n-1;
            while(k<l){
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if(sum<0){
                    k++;
                }
                else if(sum>0){
                    l--;
                }
                else{
                    vector<int>temp ={arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1]){
                        k++;
                    }
                    while(k<l && arr[l]==arr[l+1]){
                        l--;
                    }
                }
            }
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i]; // 
    }
    vector<vector<int>>result = three_sum(arr,n);
    //for each loop
    for(vector<int>triplet : result){
        for(int val:triplet){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}
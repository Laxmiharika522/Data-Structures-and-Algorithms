//find the three elements in arrays whose sum is zero(optimal)
//TC------->O(N)*O(N)
//SC ------->O(T)//ans vector to return number of consequtive triplets

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int>> three_sum(int arr[],int n){
    vector<vector<int>>ans;
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]){
            continue;//it will go to next iteration //otherwise you will end taking same triplets
        }
        int j=i+1;
        int k=n-1;
        while(j<k){//j<=k we can't take j and k should not be equal
            int sum = arr[i] + arr[j] + arr[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{//triplet
                vector<int>temp = {arr[i],arr[j],arr[k]};//already temp is in sorted order
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1]){//j<k otherwise sorted order changes
                    j++;
                }
                while(j<k && arr[k]==arr[k+1]){
                    k--;
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

//if the element is greater than other elements in right then it is called leader
//TC---->O(N^2)
//SC---->O(N) in worst case . (to return vector not used in algorithm)
#include<iostream>
#include<vector>
using namespace std;
vector<int> leaders(int arr[],int n){
    //int n=arr.size();//expression must have class type but it has type "int *"C/C++(153) int arr[]
    vector<int>result;
    for(int i=0;i<n;i++){
        int flag=1;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            result.push_back(arr[i]);
        }
    }
    return result;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>result = leaders(arr,n);
    for(int n: result){
        cout<<n<<" ";//22 12 26
    }
}

//optimal approach
//TC--->O(N) + O(NLOGN)//SORTING
//SC---->O(N) in worst case.(to return vector not used in algorithm)
/*#include<iostream>
#include<Algorithm>
#include<vector>
using namespace std;
vector<int> leaders(int arr[],int n){
    vector<int>result;
    int maxi=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi){
            result.push_back(arr[i]);
        }
        //to keep track of maximum
        maxi=max(arr[i],maxi);
    }
    //if they will mention in question for sorting we need to sorting otherwise TC--->O(N)
    sort(result.begin(),result.end());//even if it is not sorted it is in sorted order//O(NLogn)
    return result;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>result = leaders(arr,n);
    for(int n: result){
        cout<<n<<" ";//22 12 26
    }
}*/
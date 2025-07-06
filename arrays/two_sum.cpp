//find the two elements a and b in the array whose sum is equal to target
//Two types of questions are frame Yes or No and return an index
//brute
//TC---->O(N^2)
#include<iostream>
using namespace std;
string two_sum(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){//form i to n because 6+8==8+6
            if(arr[i]+arr[j]==target){//a and b should be different index elements
                return "Yes";
            }
        }
    }
    return "No";
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;    
    cout<<two_sum(arr,n,target);
}

//better
//TC----->O(N*LogN) //orderd map
//TC----->O(N*1)// unordered map in best and averege cases
//TC------>O(N*N)// unorderd map in worst case
//SC------>O(N)
/*#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> two_sum(int arr[],int n,int target){
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        int num=arr[i];
        int more=target-arr[i];
        if(mpp.find(more)!=mpp.end()){
            return {mpp[more],i};// mpp[more] gives index
        }
        mpp[num]=i; //adding of elements in map
    }
    return {-1,-1};//return type is vector
    
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;    
    vector<int>result=two_sum(arr,n,target);
    for(int n:result){
        cout<<n<<" ";
    }
}*/

//for Yes or No question this is the optimised approach
//for returning an indices better solution is the optimal solution because after sorting index value changes
//TC---->O(N) for while loop + O(NLOGN) for sorting
//SC----->O(1) we are not using extra space or O(N) we are distorting(changing) array(sorting)
/*include<iostream>
#include<algorithm>
using namespace std;
string two_sum(int arr[],int n,int target){
    int left=0,right=n-1;
    sort(arr,arr+n);//O(NLOGN)
    while(left<right){//if left crosses the array will traverse backward .left<= equal to symbol not there because elements should not equal . a and b should be different
        int sum=arr[left]+arr[right];
        if(sum==target){
            return "Yes";
        } 
        else if(sum<target){
            left++;
        }
        else{
            right--;
        }
    }
    return "NO";


}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;    
    cout<<two_sum(arr,n,target);
}*/

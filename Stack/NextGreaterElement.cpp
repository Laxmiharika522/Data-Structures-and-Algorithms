//next greater element
//Bruete
//TC--->O(N^2)
//SC--->O(N) //to return the answer not used in algorithm
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    int NGE[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        NGE[i] = -1;
    }
    //int NGE[n] ={-1};//initialize only first element to -1
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                NGE[i] = arr[j];
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<NGE[i]<<" ";
    }
}

//Optimal: Back traversal
//TC---->O(2N)
//SC----->O(N) + O(N)(To return the answer)
/*#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums){//call by refernce to avoid copying
    int n = nums.size();
    vector<int>result(n,-1);
    stack<int>s;
    for(int i =n-1;i>=0;i--){
        while(!s.empty() && s.top()<=nums[i]){
            s.pop();
        }
        if(s.empty()){
            result[i] = -1;//if tack becomes empty after poping and always lastelement is assigned to -1
        }else{
            result[i] = s.top();
        }
        s.push(nums[i]);//everytime we push the element
    }
    return result;
}
int main(){
    vector<int> nums = {4,2,5,6,7};
    vector<int> res = nextGreaterElement(nums);
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}*/
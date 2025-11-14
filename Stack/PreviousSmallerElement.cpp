//Previous smaller element
//Bruete
//TC--->O(N^2)
//SC--->O(N) //to return the answer not used in algorithm
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    int PSE[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        PSE[i] = -1;
    }
    //int PSE[n] ={-1};//initialize only first element to -1
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                PSE[i] = arr[j];
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<PSE[i]<<" ";
    }
}

//Optimal: forward traversal
//TC---->O(2N)
//SC----->O(N) + O(N)(To return the answer)
/*#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> PreviousSmallerElement(vector<int> &nums){//call by refernce to avoid copying
    int n = nums.size();
    vector<int>result(n,-1);
    stack<int>s;
    for(int i =0;i<n;i++){
        while(!s.empty() && s.top()>=nums[i]){
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
    vector<int> nums = {1,6,2,3,5,6,9};
    vector<int> res = PreviousSmallerElement(nums);
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}*/
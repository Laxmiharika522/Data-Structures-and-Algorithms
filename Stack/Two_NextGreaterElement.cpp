//Next greater element -2
//bruete 
//TC--->O(N^2)
//SC--->O(N)
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
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=i+(n-1);j++){
            int index = j%n;//to get index use circular array concept when you reach last index
            if(arr[index]>arr[i]){
                NGE[i] = arr[index];
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<NGE[i]<<" ";
    }
}

//optimal
//hypotetically we are assuming there are 2*N elements
//TC--->O(2N) + O(2N) 
//SC--->O(2N) + O(2N)(to return answer)
/*#include<iostream>
using namespace std;
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums){//call by refernce to avoid copying
    int n = nums.size();
    vector<int>result(n,-1);
    stack<int>s;
    for(int i =2*n-1;i>=0;i--){//hypotetically we assume that there are 2*n elements
        while(!s.empty() && s.top()<=nums[i%n]){
            s.pop();
        }
        if(i<n){//not all elements are considered for actuall array only we need to check hypotetical arry
            if(s.empty()){
                result[i] = -1;//if tack becomes empty after poping and always lastelement is assigned to -1
            }else{
                result[i] = s.top();
            }
        }
        s.push(nums[i%n]);//everytime we push the element
    }
    return result;
}
int main(){
    vector<int> nums = {4,8,5,6,7};
    vector<int> res = nextGreaterElement(nums);
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}*/
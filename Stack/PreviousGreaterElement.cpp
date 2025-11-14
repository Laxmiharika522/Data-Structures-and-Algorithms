#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> PreviousGreaterElement(vector<int> &nums){//call by refernce to avoid copying
    int n = nums.size();
    vector<int>result(n,-1);
    stack<int>s;
    for(int i =0;i<n;i++){
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
    vector<int> nums = {1,6,2,3,5,6,9};
    vector<int> res = PreviousGreaterElement(nums);
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
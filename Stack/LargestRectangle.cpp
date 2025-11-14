//Bruete
//TC------->O(5N)
//SC------->O(5N)
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nextSmallerElement(vector<int> &nums){//call by refernce to avoid copying
    int n = nums.size();
    vector<int>result(n,-1);
    stack<int>s;
    for(int i =n-1;i>=0;i--){
        while(!s.empty() && nums[s.top()]>=nums[i]){
            s.pop();
        }
        if(s.empty()){
            result[i] = n;//if stack becomes empty after poping and always last element is assigned to n.
            // Only for this question general NSE and PSE 
        }else{
            result[i] = s.top(); //automatically it will store the indexes
        }
        s.push(i);//everytime we push the index
    }
    return result;
}
vector<int> PreviousSmallerElement(vector<int> &nums){//call by refernce to avoid copying
    int n = nums.size();
    vector<int>result(n,-1);
    stack<int>s;
    for(int i =0;i<n;i++){
        while(!s.empty() && nums[s.top()]>=nums[i]){
            s.pop();
        }
        if(s.empty()){
            result[i] = -1;//if tack becomes empty after poping and always last element is assigned to -1
        }else{
            result[i] = s.top();
        }
        s.push(i);//everytime we push the index
    }
    return result;
}
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    vector<int>nse = nextSmallerElement(vec);
    vector<int>pse = PreviousSmallerElement(vec);
    int maxi =0;//area
    for(int i=0;i<n;i++){
        maxi = max(maxi,vec[i]*(nse[i]-pse[i]-1));//nse[i] and pse[i]  gives only ther indexes
    }
    cout<<maxi;
}


//optimal
//TC--->O(N)[TRAVERSAL] + O(N)[WHILE LOOP]
//SC--->O(N)[for stack]
/*#include<iostream>
#include<stack>
using namespace std;
int maximumArea(int arr[],int n){
    stack<int>st;
    int maxArea =0;
    int nse;
    int pse;
    int elementidx;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            elementidx = st.top();
            st.pop(); //at maximum we can pop N elements in the entire program if stack stores N elements
            nse =i;
            pse = st.empty()?-1:st.top();
            maxArea = max(maxArea,(nse-pse-1)*arr[elementidx]);
        }
        st.push(i); //we are pushing indexes
    }
    while(!st.empty()){
        nse = n;
        elementidx = st.top();
        st.pop();//this pop is also included in previous while only 
        pse = st.empty()?-1:st.top();
        maxArea = max(maxArea,(nse-pse-1)*arr[elementidx]);
    }
    return maxArea;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maximumArea(arr,n);
}*/
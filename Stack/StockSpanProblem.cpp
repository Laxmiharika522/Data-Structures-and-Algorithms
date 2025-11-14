//brute:
// TC---->O(No.of days);
// SC---->O(Total number of next cals till now);

//Let’s say you call next() N times (N days).
//Time Complexity (worst case): O(N²)
//Space Complexity: O(N)
#include<iostream>
#include<vector>
using namespace std;
class StockSpanner{
    vector<int>arr;
    public:
    StockSpanner(){
        arr= {}; //Writing arr = {}; assigns it to an empty vector (same as vector<int>()).
    }
    int next(int val){
        arr.push_back(val);
        int count =1;
        for(int i= arr.size()-2;i>=0;i--){
            if(arr[i]<=val){
                count++;
            }else{
                break;
            }
        }
        return count;
    }
};
int main(){
    StockSpanner st;
    cout<<st.next(1)<<endl;//1
    cout<<st.next(12)<<endl;//2
    cout<<st.next(11)<<endl;//1(conseutive only)
    cout<<st.next(15)<<endl;//4
    cout<<st.next(8)<<endl;//1
}


//optimal - concept of PGE
//TC---->IF THERE ARE N NEXT CALLS THEN O(N)
//SC--->O(N) //for stack
/*#include<iostream>
#include<stack>
using namespace std;
class stockSpanner{
    stack<pair<int,int>> st;
    int idx =-1; //global variable
    public:
    stockSpanner(){
        idx =-1;
        st = stack<pair<int,int>>(); // clear stack //vector has clear method
    }
    int next(int val){
        idx =idx+1;
        while(!st.empty() && st.top().first<=val){
            st.pop();
        }
        int ans = idx - (st.empty()? -1 :st.top().second); //idx is current index and top().second gives PGE index
        st.push({val,idx});
        return ans;
    }
};
int main(){
    stockSpanner sp;
    cout<<sp.next(1)<<endl;//1
    cout<<sp.next(12)<<endl;//2
    cout<<sp.next(11)<<endl;//1(conseutive only)
    cout<<sp.next(15)<<endl;//4
    cout<<sp.next(8)<<endl;//1
}*/

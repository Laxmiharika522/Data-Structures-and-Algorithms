// ans.back()[1]
// ans.back() gives {8, 10}.
// [1] means the second element (indexing starts from 0).
//TC---->O(2N) + O(NLOGN)(Sorting)// we end up taking each element two times
//SC----->O(N)//answer vector
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int>> MergeOverLappingInternal(vector<vector<int>>&arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(arr[j][0]<=end){//comparing first element with last interval second element
                end = max(end,arr[j][1]);//replace end
            }else{
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> vec(n, vector<int>(2)); 
    for (int i = 0; i < n; i++) {
        cin >> vec[i][0] >> vec[i][1];
    }
    vector<vector<int>>result = MergeOverLappingInternal(vec);
    for (auto &interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
}


//optimal
//TC---->O(N) + O(NlogN)(sorting)
//SC----->O(N)
/*#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int>> MergeOverLappingInternal(vector<vector<int>>&arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        if(ans.empty() || arr[i][0]>ans.back()[1]){//8>6 then new interval is created 
            ans.push_back(arr[i]);//current interval
        }
        else{
            ans.back()[1] = max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> vec(n, vector<int>(2)); 
    for (int i = 0; i < n; i++) {
        cin >> vec[i][0] >> vec[i][1];
    }
    vector<vector<int>>result = MergeOverLappingInternal(vec);
    for (auto &interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
}*/
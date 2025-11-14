//arr[i]<=target
#include<iostream>
#include<vector>
using namespace std;
int floor(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] <= x) {
            ans = mid;
            //look for smaller index on the right
            low = mid + 1;
        }
        else {
            high = mid - 1;    // look on the left
            
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);//vector contains n elements
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x =25;
    int ind = floor(arr, n, x);
    cout << "The floor is the index: " << ind << "\n";
    return 0;
}
//SumOfSubArrayMinimum
//BRUETE
//TC--->O(N^2)
//SC---->O(1)
/*#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //const long long MOD = pow(10,9) + 7; //constants are in 
    const long long MOD = 1000000007; // safer & faster
    long long sum =0;
    for(int i=0;i<n;i++){
        int mini = arr[i];
        for(int j=i;j<n;j++){
            mini = min(mini,arr[j]);
            sum = (sum+mini)%MOD;//if sum exceed integer range we will modulize it
        }
    }
    cout<<sum;
}*/

//Optimal: we need find the contribution of each and every element
//TC---->O(5N)
//SC---->O(4N)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> NSE(int arr[],int n) {
    vector<int>nse(n);
    stack<int>st;
    for (int i=n-1;i>=0;i--) {
        while (!st.empty() && arr[st.top()]>=arr[i]) {
            st.pop();
        }//if no element is smaller on right  put n
        nse[i] = st.empty()?n:st.top(); // if no smaller element on right
        st.push(i); // push index
    }
    return nse;
}

vector<int> PSEE(int arr[], int n) {
    vector<int> psee(n);
    stack<int> st;
    for (int i=0;i<n;i++) {
        while (!st.empty() && arr[st.top()]>arr[i]) {//see for previous smallest element we wornt check equal to condition
            st.pop();
        }//if no element is smaller on left put -1; 
        psee[i] = st.empty()?-1:st.top(); // if no smaller/equal on left
        st.push(i); // push index
    }
    return psee;
}

long long sumOfMinimum(int arr[], int n) {
    vector<int> x = NSE(arr, n);
    vector<int> y = PSEE(arr, n);

    long long total = 0;
    const long long MOD = 1000000007;

    for (int i=0;i<n;i++) {
        long long left = i-y[i];   // distance to left boundary ////PSEE deals with indexes
        long long right = x[i]-i;  // distance to right boundary
        total = (total+(right*left%MOD) *arr[i] % MOD) % MOD;
    }
    return total;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << sumOfMinimum(arr, n) << endl;
    return 0;
}

//SumOfSubArrayRanges
//bruete
//TC--->O(N^2)
//SC---->O(1)
/*#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long sum =0;
    for(int i=0;i<n-1;i++){
        int largest = arr[i];
        int smallest = arr[i];
        for(int j=i+1;j<n;j++){//we didnt considered single elements because single element range is 0 so it wont contribute in sum
            largest = max(largest,arr[j]);
            smallest = min(smallest,arr[j]);
            sum += largest-smallest;//sum of al;l subarrays range(max-min) sum
        }
    }
    cout<<sum;
}*/

//optimal
//TC---->o(5n) + o(5n) = o(10n) approximately equal to o(n)
//SC---->O(10n) approximately equal to O(n)
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int>NSE(int arr[],int n){
    vector<int>nse(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        nse[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return nse;
}
vector<int>PSEE(int arr[],int n){
    vector<int>psee(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            st.pop();
        }
        psee[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return psee;
}
vector<int>NGE(int arr[],int n){
    vector<int>nge(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }
        nge[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return nge;
}
vector<int>PGEE(int arr[],int n){
    vector<int>pgee(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]<arr[i]){
            st.pop();
        }
        pgee[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return pgee;
}
long long sumMin(int arr[],int n){
    vector<int>nse = NSE(arr,n);
    vector<int>psee = PSEE(arr,n);
    long long total =0;
    const long long MOD = 1000000007;
    for(int i=0;i<n;i++){
        int left = i-psee[i];
        int right = nse[i] - i;
        total = (total+(right*left%MOD) *arr[i] % MOD) % MOD;
    }
    return total;
}
long long sumMax(int arr[],int n){
    vector<int>nge = NGE(arr,n);
    vector<int>pgee = PGEE(arr,n);
    long long total =0;
    const long long MOD = 1000000007;
    for(int i=0;i<n;i++){
        int left = i-pgee[i];
        int right = nge[i] - i;
        total = (total+(right*left%MOD) *arr[i] % MOD) % MOD;
    }
    return total;
}
long long calculateSum(int arr[],int n){
    long long maxi = sumMax(arr,n);
    long long mini = sumMin(arr,n);
    return maxi - mini;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long sum = calculateSum(arr,n);
    cout<<sum;
}
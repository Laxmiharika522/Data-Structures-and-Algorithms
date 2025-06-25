//incase of map time complexity is O(logn)
//incase of unorderdmap time complexity is O(1) so use unorderedmap .but in worst case senario the timecomplexity is O(n).
//so if u got any error use map otherwise use unorderd_map 
#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
     int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //pre compute
    unordered_map<int,int>mpp; //in case of hash array it stores all the numbers fropm 0 to 12 but here map stores only certain elements which are present in array
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    int queries; //number of inputs to find frequency of that input
    cin>>queries;
    while(queries--){//while(0) the loop terminates
        int number;
        cin>>number; 
        //fetech
        cout<<mpp[number]<<endl;
    }
}
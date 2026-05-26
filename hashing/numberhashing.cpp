#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //precomputing
    //taking an duplicate array.hash is the name of duplicate array
    #include <vector>
    #include <algorithm> // For std::max_element
    // ...
    int max_val = 0;
    if (n > 0) {
        max_val = *std::max_element(arr, arr + n);
    }
    std::vector<int> hash(max_val + 1, 0); // Dynamically size hash array
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }

    int queries; //number of inputs to find frequency of that input
    cin>>queries;
    while(queries--){//while(0) the loop terminates
        int number;
        cin>>number; //if input querey is 15. the number 15 is not present in hashh so it will not execute(garbage value)
        //fetech
        cout<<hash[number]<<endl;
    }

}
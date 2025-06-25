//remove all duplicate elements from sorted array
//Note: The given elements are sorted
//1)bruete TC---->O(NlogN+N)  SC----->O(N)
#include<iostream>
#include<set>
using namespace std;
int main(){
    //set stores only unique elements
    set<int>st;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        st.insert(arr[i]); //set takes NlogN 
    }
    int index=0;
    //for loop takes N total O(NlogN+N)
    for(auto it:st){
        arr[index]=it;//again we are putting unquie elements in the same array
        cout<<it<<" ";//to print unique elements
        index++;
    }
    cout<<endl;
    cout<<index;
}

//2)Optimize TC--->O(N) SC---->O(1)
//given elements are sorted
//2pointer approach
/*#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[i]!=arr[j]){
            arr[i+1]=arr[j];//first element is always unique so arr[i+1]=arr[j]
            i++;
        }
    }
    //to print unique elements
    for(int k=0;k<=i;k++){
        cout<<arr[k]<<" ";

    }
    cout<<endl;
    cout<<i+1; //to print number of unique elements
}*/
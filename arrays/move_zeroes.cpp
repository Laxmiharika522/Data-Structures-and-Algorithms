//move zero to the end
//bruete approach : TC---->O(2N) SC----->O(K) Where K is the number of non-zero elements
#include<iostream>
#include<vector>
using namespace std;
void move_zeroes(int arr[],int n){
    vector<int>temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
    for(int i=0;i<temp.size();i++){
        arr[i]=temp[i];
    }
    for(int i=temp.size();i<n;i++){
        arr[i]=0;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    move_zeroes(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}

//Optimal approach --------> 2pointer approach
//TC----->O(N)     SC------->O(1) 
/*#include<iostream>
using namespace std;
void move_zeroes(int arr[],int n){
    int j=-1;
    //to find the first element where zero is found
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1){
        cout<<"there are no zeroes in an array"<<endl;
        return; //stop the function
    }
    //by using 2 pointer approach swaping zero and non-zero element
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    move_zeroes(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}*/
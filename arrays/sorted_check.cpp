//check given array is sorted or not
//if it is sorted the next element is greater than or equal to previous element
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){

        }
        else{
            cout<<"The array is not sorted";
            return -1;//if else block executes the program will terminate here it wont read next lines
        }
    }
    //if for loop executes without return statement then the array is sorted
    cout<<"The array is sorted";
}
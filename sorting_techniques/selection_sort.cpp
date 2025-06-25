//we are selecting minimum elemnt and swaping it to index 0,1,2,3,4.....
#include<iostream>
using namespace std;
void selection_sort(int arr[],int n){
    for(int i=0;i<=n-2;i++){//n-2 because we no need to last element because last element is already sorted
        int mini=i;
        for(int j=i;j<=n-1;j++){//starting from i because previous elemnts are alredy sorted and n-1 because there is an equal to symbol otherwise we could have written
        //for(int j=i;j<n;j++) or for(int j=i;j<=n-1;j++)
        if(arr[j]<arr[mini]){ //if mini index element is larger than j index element replace mini with j
            mini=j;
        }
        }
        //swaping
        int temp=arr[mini];
        arr[mini]=arr[i]; //arr[i] 
        arr[i]=temp;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selection_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}



/*#include<iostream>
using namespace std;
void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){//equal to symbol is removed
        int mini=i;
        for(int j=i;j<n;j++){
        //for(int j=i;j<n;j++) or for(int j=i;j<=n-1;j++)
        if(arr[j]<arr[mini]){ 
            mini=j;
        }
        }
        //swaping
        int temp=arr[mini];
        arr[mini]=arr[i]; //arr[i] 
        arr[i]=temp;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selection_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}*/
//Find the missing number from 1 to n
//bruete
//TC------->O(N*N) Worst.Not exactly n^2 but it is hypotetically because we breaking inner for loop after flag is 1 so we ar not completely running the inner for loop
//SC----->O(1)
#include<iostream>
using namespace std;
int find_missingnumber(int arr[],int n){
    for(int i=1;i<=n;i++){
        int flag=0;
        for(int j=0;j<n-1;j++){
            if(arr[j]==i){
                flag=1;
                break;
            }
        }
        if(flag==0){
            return i;
        }
    }
    return -1;//because we need to return an integer cumpulsory what if if condition is not true then the function wont return anything so for safety we are giving -1
}
int main(){
    int n;
    cin>>n;
    int arr[n-1];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    cout<<find_missingnumber(arr,n);
}


//better (hashing)
//TC----->O(N)+O(N)
//SC------>O(N) because of hash array
/*#include<iostream>
using namespace std;
int find_missingnumber(int arr[],int n){
    int hash[n+1]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]=1;
    }
    for(int i=1;i<n;i++){
        if(hash[i]==0){
          return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n-1];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    cout<<find_missingnumber(arr,n);
}*/

//optimal
//sum method
//TC----->O(N)
//SC------>O(1)
/*#include<iostream>
using namespace std;
int find_missingnumber(int arr[],int n){
    int sum1=(n*(n+1))/2;
    int sum2=0;
    for(int i=0;i<n-1;i++){
        sum2+=arr[i];
    }
    return sum1-sum2;
}
int main(){
    int n;
    cin>>n;
    int arr[n-1];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    cout<<find_missingnumber(arr,n);
}*/


//Xor method much better than sum method 
//because if u have numbers 10^5 sum of numbers is 10^10 sum variable of data type int cannot store it.It requires long int data type
//remember: 0^0=0 , 2^2=0 , 0^2=2 
//TC---->O(N)
//SC----->O(1)
/*#include<iostream>
using namespace std;
int find_missingnumber(int arr[],int n){
    int xor1=0;
    int xor2=0;
    for(int i=0;i<n-1;i++){
        xor2=xor2^arr[i];
        xor1=xor1^(i+1);
    }
    xor1=xor1^n;
    return xor1^xor2;

}
int main(){
    int n;
    cin>>n;
    int arr[n-1];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    cout<<find_missingnumber(arr,n);
}*/
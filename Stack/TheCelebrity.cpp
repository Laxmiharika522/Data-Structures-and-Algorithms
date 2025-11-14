//brute
//TC----->O(N^2) + O(N)
#include<iostream>
using namespace std;
#define MAX 100
int calculateTheCeleb(int arr[][MAX],int n){
    int knowMe[n] ={0};
    int Iknow[n] ={0};
    for(int i=0;i<n;i++){//O(N^2)
        for(int j=0;j<n;j++){
            if(arr[i][j]==1){
                knowMe[j]++;
                Iknow[i]++;
            }
        }
    }
    for(int i=0;i<n;i++){//O(N)
        if(knowMe[i] == n-1 && Iknow[i]==0){
            return i;
        }
    }
    return -1;

}
int main(){
    int n;
    cin>>n;
    int arr[MAX][MAX];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<calculateTheCeleb(arr,n);
}


//OPtimal
//TC----->O(N) + O(N)
//SC---->O(1)
/*#include<iostream>
using namespace std;
#define MAX 100
int calculateTheCeleb(int arr[][MAX],int n){
    int top =0;
    int bottom = n-1;
    while(top<bottom){//O(N)
        if(arr[top][bottom]==1){
            top = top+1;
        }else if(arr[bottom][top]==1){
            bottom --;
        }else{
            top++;
            bottom--;
        }
    }
    if(top>bottom){
        return -1;
    }
    for(int i=0;i<n;i++){//O(N)
        if(i==top){//diagonal element always zero no need to check
            continue;
        }
        if(arr[top][i] == 1 || arr[i][top]==0){//checking entire row and entire column
            return -1;
        }
    }
    return top;
}
int main(){
    int n;
    cin>>n;
    int arr[MAX][MAX];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<calculateTheCeleb(arr,n);
}*/
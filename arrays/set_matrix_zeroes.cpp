//find the zeroes in a mtrix and make its column andd row as zeroes
//TC--------> O(N^2)*O(2*N) + O(N*N) which is nearly equal to O(N^3) if N and M are equal
//SC-------->O(1)
#include<iostream>
using namespace std;
const int MAX=100;
void Markrow(int arr[][MAX],int i,int m){//O(N)
    for(int j=0;j<m;j++){
        if(arr[i][j]!=0){
            arr[i][j]=-1;
        }
    }
}
void Markcol(int arr[][MAX],int j,int n){//O(N)
    for(int i=0;i<n;i++){
        if(arr[i][j]!=0){
            arr[i][j]=-1;
        }
    }
}
void set_matrix(int arr[][MAX],int n,int m){//coloumn size is compulsory//O(N^2)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                Markrow(arr,i,m);//O(N)
                Markcol(arr,j,n);//O(N)
            }
        }
    }
    for(int i=0;i<n;i++){//O(N^2)
        for(int j=0;j<m;j++){
            if(arr[i][j]==-1){
                arr[i][j]=0;
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    // variable-length arrays (int arr[n][m];) are a GCC extension, not part of standard C++. Your functions expect:
    // int arr[][MAX]; // with fixed column size
    // So you must use a fixed-size 2D array, like arr[MAX][MAX].
    int arr[MAX][MAX];//2d arrays should initialed with fixed length
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    set_matrix(arr,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


//better
//TC---->O(2*N*M)
//SC---->O(N) + O(M)
/*#include<iostream>
using namespace std;
const int MAX=100;
void set_matrix(int arr[][MAX],int n,int m){//coloumn size is compulsory//O(N^2)
    int row[n]={0};//O(N)
    int col[m]={0};//O(M)
    for(int i=0;i<n;i++){//O(N*M)
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){//O(N*M)
        for(int j=0;j<m;j++){
            if(col[j]==1 || row[i] ==1){
                arr[i][j]=0; //either row or column is zero make that element as zero
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    // variable-length arrays (int arr[n][m];) are a GCC extension, not part of standard C++. Your functions expect:
    // int arr[][MAX]; // with fixed column size
    // So you must use a fixed-size 2D array, like arr[MAX][MAX].
    int arr[MAX][MAX];//2d arrays should initialed with fixed length
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    set_matrix(arr,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}*/

//Optimal
//TC----->O(2*N*M)
//SC------>O(1)
/*#include<iostream>
using namespace std;
const int MAX=100;
void set_matrix(int arr[][MAX],int n,int m){////coloumn size is compulsory//O(N^2)
    int colo=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                //in bruete force we are marking entire row and colum as zero but here are marking only 1st row(0th) and 1st column(0th) as zero
                arr[i][0]=0;//1st row and coloumn is already runned
                if(j!=0){
                    arr[0][j]=0;
                }
                if(j==0){
                    colo=0;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][j]!=0){
                //check for row and coloumn
                if(arr[0][j]==0 ||  arr[i][0]==0){
                    arr[i][j]=0;
                }

            }
        }
    }
    if(arr[0][0]==0){
        for(int j=0;j<m;j++){
            arr[0][j]=0;
        }
    }
    if(colo==0){
        for(int i=0;i<n;i++){
            arr[i][0]=0;
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    // variable-length arrays (int arr[n][m];) are a GCC extension, not part of standard C++. Your functions expect:
    // int arr[][MAX]; // with fixed column size
    // So you must use a fixed-size 2D array, like arr[MAX][MAX].
    int arr[MAX][MAX];//2d arrays should initialed with fixed length
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    set_matrix(arr,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}*/


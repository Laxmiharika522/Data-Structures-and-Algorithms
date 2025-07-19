//rotate an array by 90 degrees

//TC-----> O(N^2)
//SC----->O(N^2) all elements are stord in 2D array
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> rotate(vector<vector<int>>arr,int n){
    vector<vector<int>>result(n,vector<int>(n));    
    for(int i=0;i<n;i++){//O(N^2)
        for(int j=0;j<n;j++){
            result[j][n-i-1] = arr[i][j];
        }
    }
    return result;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>>result = rotate(arr,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}

//optimal
/*#include<iostream>
#include<vector>
#include<algorithm>
//TC---->O(N/2 * N/2) + O(N * N/2)
//SC----->O(1)
using namespace std;
vector<vector<int>> rotate(vector<vector<int>>arr,int n){  
    for(int i=0;i<n-2;i++){//O(N/2 * N/2) we swaping half of the loop matrix only
        for(int j=i+1;j<n-1;j++){//swaping
            int temp=arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
        //reverse row
        //begin() and end() are standard functions that are used with 1D vectors only not 2D
        //O(N*N/2)
        for(int j=0;j<n;j++){//O(N)
            reverse(arr[i].begin(),arr[i].end());//accessing each row .worst case reverse function will take O(N/2)
        }
    }
    return arr;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>>result = rotate(arr,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}*/

//u can do with arrays also but use vectors
/*#include<iostream>
using namespace std;
const int MAX =10;
//we cannot return 2D arrays we can return 2D vector
void rotate(int arr[][MAX],int result[][MAX],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            result[j][n-i-1] = arr[i][j];
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[MAX][MAX];
    int result[MAX][MAX];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    rotate(arr,result,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}*/

//transpose
/*#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){//j=i+1 to avoid duplicate swaps example: i=1 j=0 [1][0] swaped with [0][1] but [0][1] is already swaped in iteration only
            int temp=arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}*/


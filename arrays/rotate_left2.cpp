//Left rotate an array by D places
//1)bruete  ----->TC---->O(N+D)
//SC----->O(D)
#include<iostream>
using namespace std;
void rotateleft(int arr[],int d,int n){
    d=d%n;//after n rotates the array will be in the same position so if the number is big we use %
    //ex: array contains 5 elements if d=17 we should only 2 left rotate which is equivalent to 17 rotates
    int temp[d];
    //adding in temp array
    for(int i=0;i<d;i++){//O(D)
        temp[i]=arr[i];
    }
    //moving remaining elements to start
    for(int i=d;i<n;i++){//O(N-D)
        arr[i-d]=arr[i];
    }
    //putting temp array eleemnts in main array
    int j=0;
    for(int i=n-d;i<n;i++){//O(D)
        arr[i]=temp[j];//arr[n-d]=temp[i-(n-d)];
        j++;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int d;//number of places to rotate
    cin>>d;
    rotateleft(arr,d,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


//O(2N) is not that much optimal as compared to O(N+d) but in optimal solution space complexity is O(1) where as in bruete is O(D)
//2)optimal solution
//TC--->O(2N)
//space complexity O(1)
/*#include<iostream>
using namespace std;
void reverse(int arr[], int n, int m) {
    for (int i=0;i<(m-n)/2;i++) {
        int temp=arr[n+i];
        arr[n+i]=arr[m-1-i];
        arr[m-1-i]=temp;
    }
}

void rotateleft(int arr[],int n,int d){
    //u can use direct reverse inbult function or use write ur own reverse function
    d=d%n;
    reverse(arr,0,d);//O(d)
    reverse(arr,d,n);//O(N-D)
    reverse(arr,0,n);//O(N)
    //OVERALL O(2N)
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int d;//number of places to rotate
    cin>>d;
    rotateleft(arr,n,d);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}*/

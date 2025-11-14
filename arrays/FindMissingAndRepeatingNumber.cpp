//you have given an array which contais 1 to n elements and in that array one number is repeating and one number is missing find missing and repeating numbers
//brute
//TC----->O(N^2)
//SC------>O(1)
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int missing =-1;
    int repeating =-1;
    for(int i=1;i<=n;i++){
        int count =0;
        for(int j=0;j<n;j++){
            if(arr[j]==i){
                count++;
            }
        }
        if(count==0){
            missing =i;
        }else if(count==2){
            repeating =i;
        }
        if(missing!=-1 && repeating !=-1){//once we found repeating and missing break it
            break;
        }
    }
    cout<<"The repeating number is: "<<repeating<<endl;
    cout<<"The missing number is: "<<missing<<endl;

}


//better
//hash array
//TC---> O(N) + O(N) = O(2N)
//SC---> O(N)(hash array)
/*#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int hash[n+1] ={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    int missing =-1;
    int repeating =-1;
    for(int i=1;i<=n;i++){
        if(hash[i]==2){
            repeating =i;
        }else if(hash[i]==0){
            missing =i;
        }
        if(repeating!=-1 && missing!=-1){
            break;
        }
    }   
    cout<<"The repeating number is: "<<repeating<<endl;
    cout<<"The missing number is: "<<missing<<endl;
}*/



//optimal - maths
//tc---> O(N)
//SC--->O(1)
/*#include<iostream>
#include<vector>
using namespace std;
vector<int> findMissingRepeating(vector<int>a){
    long long n = a.size(); //since we are dealing with squares
    long long sn = (n*(n+1))/2;
    long long s2n = (n*(n+1)*(2*n+1))/6;
    long long s=0,s2=0;
    for(int i=0;i<n;i++){
        s+=a[i];
        s2+=(long long)a[i] * (long long)a[i];
    }
    int val1 = s - sn;
    int val2 = s2 - s2n;
    val2 = val2/val1;
    long long x = (val1+val2)/2;
    long long y = x - val1;
    return {(int) x,(int) y};
}
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    vector<int>result = findMissingRepeating(vec);
    cout<<result[0]<<endl;
    cout<<result[1]<<endl;
}*/



//OPTIMAL - XOR METHHOD
//TC--->O(4N) WHICH IS APPROXIMATELY EQUAL TO O(N)
//SC--->O(1)
/*#include<iostream>
#include<vector>
using namespace std;
vector<int> findMissingRepeating(vector<int>a){
    long long n = a.size(); //since we are dealing with squares
    int xr =0;
    for(int i=0;i<n;i++){
        xr = xr^a[i];
        xr = xr^(i+1);
    }
    int bitno =0;
    while(1){
        if((xr & (1<<bitno))!=0){
            break;
        }
        bitno++;
    }
    int zero=0;
    int one =0;
    for(int i=0;i<n;i++){
        if((a[i] & (1<<bitno))!=0){
            one = one^a[i];
        }else{
            zero = zero^a[i];
        }
    }
    for(int i=0;i<=n;i++){
        if((i & (1<<bitno))!=0){
            one = one^i;
        }else{
            zero = zero^i;
        }
    }
    int cnt =0;
    for(int i=0;i<n;i++){//to check whichis repeating or which is missing
        if(a[i]==zero){
            cnt++;
        }
    }
    if(cnt==2){
        return {zero,one};//missing ,repeating
    }else{
        return {one,zero};
    }
    
}
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    vector<int>result = findMissingRepeating(vec);
    cout<<"missing: "<<result[0]<<endl;
    cout<<"repeating: "<<result[1]<<endl;
}*/
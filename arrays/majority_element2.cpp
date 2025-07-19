//find the element which apperas more than N/3 times in an given array
//in general in any array the element should appear more than N/3 times than atmost we can have only two elements
//bruete
//TC------->O(N^2)
//SC-------->O(1)
#include<iostream>
#include<vector>
using namespace std;
vector<int> majority_element(int arr[],int n){
    vector<int>vec;
    for(int i=0;i<n;i++){
        if(vec.size()==0 || vec[0]!=arr[i]){//we are checking for vec[0] only after second element pushed back we need to manually stop it
            int cnt =0;
            for(int j=0;j<n;j++){//for each and every element we are checking
                if(arr[i]==arr[j]){
                    cnt++;
                }
            }
            if(cnt>n/3){
                vec.push_back(arr[i]);
            }
            if(vec.size()==2){//other wise 
                break;
            }
        }
    }
    return vec;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i]; // 1 1 1 3 3 3 2 2
    }
    vector<int>result = majority_element(arr,n);
    //for each loop
    for(int i:result){
        cout<<i<<" ";//1 3
    }
}

//better
//hashing
//TC------->O(N)//best case in unordered map
//SC--------O(N) //all the elements stored in map
/*#include<iostream>
#include<vector>
#include<unordered_map>//takes O(1) in best case and average cases
using namespace std;
vector<int> majority_element(int arr[],int n){
    unordered_map<int,int>mpp;
    vector<int>vec;
    for(int i=0;i<n;i++){//O(NLOGN)
        //if key is not present it will create key and it will increase
        mpp[arr[i]]++; //this operation takes o(logn) in case of orderd map but in un_ordered map it takes O(1) in best cases and O(N)in worst case
        if(mpp[arr[i]]==(n/3)+1){//we are inside the loop so dont take mpp[arr[i]]>(n/3+1)
            vec.push_back(arr[i]);
        }
    }
    return vec;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i]; //1 1 1 3 3 2 2 2
    }
    vector<int>result = majority_element(arr,n);
    for(int i:result){
        cout<<i<<" ";//1 2
    }
}*/

//optimal 
//If different element is presennt subract it if same element is present add it
//TC--->O(2N)
//SC---->O(1) //we used vector but it has only 2 elements
/*#include<iostream>
#include<vector>
#include<Algorithm>
using namespace std;
vector<int> majority_element(int arr[],int n){
    int cnt1 =0,cnt2 =0;
    int ele1 =INT_MIN,ele2=INT_MIN;
    for(int i=0;i<n;i++){//O(N)
        if(cnt1==0 && ele2!=arr[i]){//the element which we are choosing for ele1 should not be equal to ele2
            cnt1=1;//setting
            ele1 = arr[i];
        }
        else if(cnt2==0 && ele1!=arr[i]){
            cnt2=1;
            ele2 = arr[i];
        }
        else if(arr[i]==ele1){
            cnt1++;
        }
        else if(arr[i] == ele2){
            cnt2++;
        }
        else{
            //subtracting from both counts
            cnt1--;
            cnt2--;
        }
    }
    vector<int>vec;
    //checking 
    cnt1 =0,cnt2=0;
    for(int i=0;i<n;i++){//O(N)
        if(ele1==arr[i]){
            cnt1++;
        }
        //we have to check both cases so we use two if's not one if and one else
        if(ele2==arr[i]){
            cnt2++;
        }
    }
    int mini = (int)n/3;
    if(cnt1>mini){
        vec.push_back(ele1);
    }
    if(cnt2>mini){
        vec.push_back(ele2);
    }
    sort(vec.begin(),vec.end());//only 2 elements are there so Tc for this statement is O(2LOG2)// which is constant
    return vec;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i]; //1 1 1 3 3 2 2 2
    }
    vector<int>result = majority_element(arr,n);
    for(int i:result){
        cout<<i<<" ";//1 2
    }
}*/
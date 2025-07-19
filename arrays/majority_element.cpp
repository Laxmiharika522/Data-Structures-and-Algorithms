//Find the majority element which appears more than N/2 times \
//at most we can have only one element appeaaring more than N/2 times
//brute:
//TC------>O(N^2)
/*#include<iostream>
#include<vector>
using namespace std;
int majority_element(vector<int>vec){
    for(int i=0;i<vec.size();i++){
        int cnt=0;
        for(int j=0;j<vec.size();j++){
            if(vec[j]==vec[i]){
                cnt++;
            }
        }
        if(cnt>(vec.size()/2)){
            return vec[i];
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    cout<<majority_element(vec);
}*/

//Better ------>Hashing
//TC------> O(NlogN)+O(N)
//SC-------> O(N)
/*#include<iostream>
#include<vector>
#include<map>
using namespace std;
int majority_element(vector<int>vec){
    map<int,int>mpp;
    for(int i=0;i<vec.size();i++){
        mpp[vec[i]]++;
    }
    for(auto it:mpp){
        if(it.second>(vec.size()/2)){
            return it.first;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    cout<<majority_element(vec);
}*/


//optimal
//Moore's voting algorithm
//TC----->O(N) + O(N)(for checking)
//SC------>O(1);
/*#include<iostream>
#include<vector>
using namespace std;
int majority_element(vector<int>vec){
   int cnt=0;
   int el;
   for(int i=0;i<vec.size();i++){
        if(cnt==0){
            cnt =1 ;
            el=vec[i];
        }
        else if(vec[i]==el){
            cnt++;
        }
        else{
            cnt--;
        }
   }
   //checking
   int cnt1=0;
   for(int i=0;i<vec.size();i++){
        if(vec[i]==el){
           cnt1++; 
        }
        if(cnt1>(vec.size()/2)){
            return el;
        }
   }
   return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    cout<<majority_element(vec);
}*/


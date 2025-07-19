//find out all the trplets giving the sum 0
//all the triplets should be unique and single element cannot be taken twice. If same element present two times in an array you can take it
//TC---->O(N^3)+O(LOG(T));
//SC----->O(2*LOG(T)); //one for vector ,one for set
#include<iostream>
#include<set>
#include<Algorithm>
#include<vector>
using namespace std;
vector<vector<int>> three_sum(int arr[],int n){
   set<vector<int>>st; //to store all elements in set O(no.of unique triplets)
   for(int i=0;i<n;i++){//O(N^3)
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int>temp = {arr[i],arr[j],arr[k]};//only three elements
                    sort(temp.begin(),temp.end());//only 3 elements
                    st.insert(temp);//O(LOG(No.of unique triplets));
                }
            }
        }
   }
   vector<vector<int>>ans(st.begin(),st.end()); //O(no.of unique triplets) ---->SC
   return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i]; // 
    }
    vector<vector<int>>result = three_sum(arr,n);
    //for each loop
   for(vector<int>triplet : result){
        for(int val:triplet){
            cout<<val<<" ";
        }
        cout<<endl;
   }
}


//better
//TC------>O(N^2)*O(LOGM)
//SC------->O(N) //hashset + O(no.of unique triplets)//set + O(no.of unique triplets)//to return answer
/*#include<iostream>
#include<set>
#include<Algorithm>
#include<vector>
using namespace std;
vector<vector<int>> three_sum(int arr[],int n){
   set<vector<int>>st;
   for(int i=0;i<n;i++){
        set<int>hashset;//empty the set for every ith iteration //O(LOGM)//M means variable
        for(int j=i+1;j<n;j++){
            int k = -(arr[i]+arr[j]);
            if(hashset.find(k)!=hashset.end()){//which means it is there in set
                vector<int>temp = {arr[i],arr[j],k};//only three elements
                sort(temp.begin(),temp.end());//only 3 elements
                st.insert(temp);//O(LOG(No.of unique triplets));
            }
            hashset.insert(arr[j]); //every time we need to accumulate in hashset if element is not present in hashset
        }
   }
   vector<vector<int>>ans(st.begin(),st.end()); //O(no.of unique triplets) ---->SC
   return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i]; // 
    }
    vector<vector<int>>result = three_sum(arr,n);
    //for each loop
   for(vector<int>triplet : result){
        for(int val:triplet){
            cout<<val<<" ";
        }
        cout<<endl;
   }
}*/
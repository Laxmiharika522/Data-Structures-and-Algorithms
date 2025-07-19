//TC--->O(N^4)
//SC--->O(2*No of unique quads)
/*#include<iostream>
#include<set>
#include<Algorithm>
#include<vector>
using namespace std;
vector<vector<int>> three_sum(int arr[],int n){
   set<vector<int>>st; //to store all elements in set O(no.of unique triplets)
   for(int i=0;i<n;i++){//O(N^3)
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                        if(arr[i]+arr[j]+arr[k]+arr[l]==0){
                        vector<int>temp = {arr[i],arr[j],arr[k],arr[l]};//only four elements
                        sort(temp.begin(),temp.end());//only 4 elements
                        st.insert(temp);//O(LOG(No.of unique triplets));
                    }
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
}*/


//TC---->O(N^2)*O(LOGM)//used in hash_set M because the iterations of k loop varies so we take M
//SC----->O(N)//hash set stores all the elements + O(2*no.of quads); 
#include<iostream>
#include<set>
#include<Algorithm>
#include<vector>
using namespace std;
vector<vector<int>> four_sum(int arr[],int n){
   set<vector<int>>st;
    for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                set<int>hashset;
                for(int k=j+1;k<n;k++){
                int l = -(arr[i]+arr[j]+arr[k]);
                if(hashset.find(l)!=hashset.end()){//which means it is there in set
                    vector<int>temp = {arr[i],arr[j],arr[k],l};//only four elements
                    sort(temp.begin(),temp.end());//only 4 elements
                    st.insert(temp);//O(LOG(No.of unique triplets));
                }
                hashset.insert(arr[k]); //every time we need to accumulate in hashset if element is not present in hashset
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
    vector<vector<int>>result = four_sum(arr,n);
    //for each loop
   for(vector<int>triplet : result){
        for(int val:triplet){
            cout<<val<<" ";
        }
        cout<<endl;
   }
}
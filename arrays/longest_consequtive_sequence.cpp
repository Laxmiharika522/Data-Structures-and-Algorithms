//find the longest consequtive sequence and return its length
//TC----->O(N^3)
//SC------>O(1)
#include<iostream>
using namespace std;
int linearsearch(int arr[],int x,int n){//O(N)
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return 1;
        }
    }
    return 0;
}
int longest_sequence(int arr[],int n){//O(N)
    int longest=1;
    for(int i=0;i<n;i++){
        int x=arr[i];//assuming this element has futher seqence we are serching for x+1 x+2 x+3...... since consequtive sequence
        int cnt=1;//first element
        while(linearsearch(arr,x+1,n)==1){//O(N) and inner linear search O(N^2)
            x=x+1;
            cnt=cnt+1;
        } 
        longest=max(longest,cnt);
    }
    return longest;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<longest_sequence(arr,n);
}


//better
//TC----->O(NLOGN) sorting + O(N)
//SC----->O(N) WE are changing array if not O(1)
/*#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int longest_sequence(vector<int>vec){
    sort(vec.begin(),vec.end());
    int longest=1;
    int cntcurr=0;
    int last_smaller=INT_MIN;
    for(int i=0;i<vec.size();i++){
        if(vec[i]-1 == last_smaller){//if ther is any element whose previous element is in last_smaller then that is consequtive series increase the count value and update last_smaller
            cntcurr++;
            last_smaller=vec[i];//replace last element with present element
        }
        else if(vec[i]!=last_smaller){//finding the last_smaller
            cntcurr=1;//we found smallest element
            last_smaller=vec[i];
        }
        longest=max(longest,cntcurr);
    }
    return longest;
}
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    cout<<longest_sequence(vec); //4
}*/


//optimal
//TC------>O(N)+O(N)+O(N) = O(3N)
//SC------->O(N) //WORst case assuming all elements stored in set
/*#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<vector>
using namespace std;
int longest_sequence(vector<int>vec){
    int n= vec.size();
    if(n==0){
        return 0;
    }
    int longest=1;
    unordered_set<int>st;//St takes O(1) in best and average case in worst case it will take O(N)
    for(int i=0;i<n;i++){//O(1.N)= O(N)
        st.insert(vec[i]);//gives unique elements in unordered_order
    }
    //O(2N)
    for(auto it: st){//O(N)
        if(st.find(it-1)==st.end()){//previous element is not present in the set that means this is the initial element or starting element
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){//O(N)
                cnt++;
                x=x+1;
            }
            longest=max(longest,cnt);
        }
    }
    return longest;
}
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    cout<<longest_sequence(vec);
}*/
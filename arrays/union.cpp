//find the union of two sorted vectors or arrays
//bruete
//Total TC---->O(N1logN+N2logN)  
//SC------>O(N1+N2) for set + O(N1+N2) for unionoftwoarrays(we are using this array to get output only not in our algorithm)
#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int> unions(vector<int>v1,vector<int>v2,int n1,int n2){
    set<int>st;//O(logN) Where N is the number of elements in set
    for(int i=0;i<n1;i++){//O(N1LOGN)
        st.insert(v1[i]);
    }
    for(int i=0;i<n2;i++){//O(N2LOGN)
        st.insert(v2[i]);
    }
   vector<int>unionoftwovectors;
    int i=0;
    for(auto it:st){//O(N1+N2) in worst case
        unionoftwovectors.push_back(it);
    }
    return unionoftwovectors;
}
int main(){
    int n1;
    cin>>n1;
    vector<int>vec1;
    for(int i=0;i<n1;i++){
        //cin>>vec1[i]; it is not working follow the following method
        int x;
        cin>>x;
        vec1.push_back(x);
    }
    int n2;
    cin>>n2;
    vector<int>vec2;
    for(int i=0;i<n2;i++){
        //cin>>vec2[i];
        int x;
        cin>>x;
        vec2.push_back(x);
    }
    vector<int>result = unions(vec1, vec2, n1, n2);
    cout << "Union: ";
    for(int num:result) {
        cout<<num<<" ";
    }
}


//optimal approach
//TC-------->O(N1+N2) //we are comparing each and every element
//SC--------->O(N1+N2) //in worst case if all elements are unique //not in algorithm just to return an array
/*#include<iostream>
#include<vector>
using namespace std;
vector<int> unions(vector<int>v1,vector<int>v2,int n1,int n2){
    vector<int>unionvector;
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(v1[i]<=v2[j]){
            if(unionvector.size()==0 || unionvector.back()!=v1[i]){
                unionvector.push_back(v1[i]);//small element is pushed back
            }
            i++;//irrespective of adding the element we will the i pointer
        }
        else{
            if(unionvector.size()==0 || unionvector.back()!=v2[j]){
                unionvector.push_back(v2[j]);//small element is pushed back
            }
            j++;//irrespective of adding the element we will the i pointer
        }
    }
    while(j<n2){//if there are some elements in second vector
        if(unionvector.size()==0 || unionvector.back()!=v2[j]){
                unionvector.push_back(v2[j]);//small element is pushed back
        }
        j++;//irrespective of adding the element we will the i pointer
    }
    while(i<n1){
        if(unionvector.size()==0 || unionvector.back()!=v1[i]){
            unionvector.push_back(v1[i]);//small element is pushed back
        }
        i++;//irrespective of adding the element we will the i pointer
    }
    return unionvector;
}
int main(){
    int n1;
    cin>>n1;
    vector<int>vec1;
    for(int i=0;i<n1;i++){
        int x;
        cin>>x;
        vec1.push_back(x);
    }
    int n2;
    cin>>n2;
    vector<int>vec2;
    for(int i=0;i<n2;i++){
        int x;
        cin>>x;
        vec2.push_back(x);
    }
    vector<int>result = unions(vec1, vec2, n1, n2);
    cout << "Union: ";
    for(int num:result) {
        cout<<num<<" ";
    }
}*/
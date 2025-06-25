//Find the intersection of two sorted vectors
//bruete force approach
//TC----->O(N1*N2)
//SC------>O(N2)
#include<iostream>
#include<vector>
using namespace std;
vector<int> intersection(vector<int>vec1,vector<int>vec2,int n1,int n2){
    vector<int>visited(n2,0);
    vector<int>ans;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(vec1[i]==vec2[j] && visited[j]==0){
                ans.push_back(vec1[i]);
                visited[j]=1;
                break;
            }
            if(vec2[j]>vec1[i]){
                break;
            }
        }
    }
    return ans;

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
    vector<int>result = intersection(vec1, vec2, n1, n2);
    cout << "Intersection: ";
    for(int num:result) {
        cout<<num<<" ";
    }
}


//optimal: 2pointer approach
//TC------>O(N1+N2) WORST CASE
//SC------->O(1)
/*#include<iostream>
#include<vector>
using namespace std;
vector<int> intersection(vector<int>vec1,vector<int>vec2,int n1,int n2){
    int i=0;
    int j=0;
    vector<int>ans;
    while(i<n1 && j<n2){
        if(vec1[i]<vec2[j]){
            i++;
        }else if(vec2[j]<vec1[i]){
            j++;
        }else{
            ans.push_back(vec1[i]);
            i++;
            j++;
        }
    }
    return ans;
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
    vector<int>result=intersection(vec1, vec2, n1, n2);
    cout << "Intersection: ";
    for(int num:result) {
        cout<<num<<" ";
    }
}*/
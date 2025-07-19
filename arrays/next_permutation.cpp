//find the next permutation
//TC-------->O(3N)
//SC-------->O(N) we are changing the array or O(1) because we are not creating extra space
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> next_permutation(vector<int>vec){
    int n=vec.size();
    int index=-1;
    //to find dec
    for(int i=n-2;i>=0;i--){//O(N)
        if(vec[i]<vec[i+1]){
            index=i;
            break;
        }
    }
    //if there is no dec that means it is the last permutation
    if(index==-1){//last permutation
        reverse(vec.begin(),vec.end());
        return vec;
    }
    //after find dec we need to replace with smallest element but greater than dec
    for(int i=n-1;i>index;i--){//O(N)
        if(vec[i]>vec[index]){
            swap(vec[i],vec[index]);
            break;
        }
    }
    //after replacing dec we need to find nearest value to the dec
    reverse(vec.begin()+index+1,vec.end());//O(N)
    return vec;

}
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    vector<int>res=next_permutation(vec);
    for(auto it:res){
        cout<<it<<" ";
    }
}
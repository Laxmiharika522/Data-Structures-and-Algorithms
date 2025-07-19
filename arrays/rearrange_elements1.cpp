//if there are no equal positive and negative elements
//If any of positive and negative elements left add them at the end and without altering the order
//TC----->O(N)+O(MIN(neg,pos))+O(remaining elements)==O(N)+O(N) in worst case
//SC----->O(N);
//This is only solution for this type of question
#include<iostream>
#include<vector>
using namespace std;
void rearrange(vector<int>vec){
    int n=vec.size();
    vector<int>pos,neg;
    for(int i=0;i<n;i++){//O(N)
         if(vec[i]>0){
            pos.push_back(vec[i]);
        }else{
            neg.push_back(vec[i]);
        }
    }
    if(pos.size()>neg.size()){
        for(int i=0;i<neg.size();i++){
            vec[2*i]=pos[i];
            vec[2*i+1]=neg[i];
        }
        int index=neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            vec[index]=pos[i];
            index++;
        }
    }
    else{//if there are more negative elements
        for(int i=0;i<pos.size();i++){
            vec[2*i]=pos[i];
            vec[2*i+1]=neg[i];
        }
        int index=pos.size()*2;
        for(int i=pos.size();i<neg.size();i++){
            vec[index]=neg[i];
            index++;
        }
    }
    for(auto it:vec){
        cout<<it<<" ";
    }
}
int main(){
     int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    rearrange(vec);
}
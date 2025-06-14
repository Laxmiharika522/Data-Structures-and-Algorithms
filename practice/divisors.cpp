//time complexity O(n)
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
}

//time complexity O(sqrt(n))
/*#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
            if((n/i)!=i){// ex: n=36 ; 6*6=36 36/6=6 again it will print 6 so we need to ommit it
                cout<<n/i<<" ";
            }
        }
    }
}*/

//to get in sorted order
/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printdivisors(int n){
    vector<int>v;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            v.push_back(i);
            if((n/i)!=i){// ex: n=36 ; 6*6=36 36/6=6 again it will print 6 so we need to ommit it
                v.push_back(n/i);
            }
        }
    }
    sort(v.begin(),v.end());
    for(auto it:v){
        cout<<it<<" ";
    }

}
int main(){
    int n;
    cin>>n;
    printdivisors(n);
}*/


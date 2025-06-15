//Time complexity and space complexity is O(N)
//parametarized
#include<iostream>
using namespace std;
void fact(int n,int prod){
    if(n<1){
        cout<<prod;
        return;
    }
    fact(n-1,prod*n);

}
int main(){
    int n;
    cin>>n;
    fact(n,1);
}

//functional
/*#include<iostream>
using namespace std;
int fact(int n){
    if(n==1){
        return 1;
    }
    return n*fact(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<fact(n);
}*/
//Time complexity and space complexity is O(N)
//parametarized
#include<iostream>
using namespace std;
void sumn(int n,int sum){
    if(n<1){
        cout<<sum;
        return;
    }
    sumn(n-1,sum+n);

}
int main(){
    int n;
    cin>>n;
    sumn(n,0);
}

//functional
/*#include<iostream>
using namespace std;
int sumn(int n){
    if(n==0){
        return 0;
    }
    return n+sumn(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<sumn(5);
}*/
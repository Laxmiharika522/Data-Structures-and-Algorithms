#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count=0;
    while(n>0){
        n=n/10;
        count++;
    }
    cout<<count;
}

//shortcut
/*#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count=(int)(log10(n))+1;
    cout<<count;
}*/


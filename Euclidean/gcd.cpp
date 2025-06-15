//TIME COMPLEXITY O(log(min(a,b))) //base pi(unknown variable)
#include<iostream>
using namespace std;
void gcd(int n,int m){
    while(n>0 && m>0){
        if(n>m){
            n=n%m;
        }else{
            m=m%n;
        }
    }
    if(n==0){
        cout<<m;
    }else{
        cout<<n;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    gcd(n,m);

}

// #include<iostream>
// using namespace std;
// void gcd(int n,int m){
//     while(n>0){
//         int k=m%n;
//         int temp=n;
//         n=k;
//         m=temp;
//     }
//     cout<<m;

// }
// int main(){
//     int x,y;
//     cin>>x>>y;
//     int n=min(x,y);
//     int m=max(x,y);
//     gcd(n,m);
    
// }

/*#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int gcd=1;
    for(int i=1;i<=min(n,m);i++){
        if(n%i==0 && m%i==0){
            gcd=i;
        }
    }
    cout<<gcd;
}*/

/*#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int gcd=1;
    for(int i=min(n,m);i>=1;i--){
        if(n%i==0 && m%i==0){
            gcd=i;
            break;
        }
    }
    cout<<gcd;
}*/
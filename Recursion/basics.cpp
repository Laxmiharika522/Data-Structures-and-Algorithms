//Time complexity: calls the function n times so O(n)
//Space complexity or stack complexity(how many times ) is O(n)
#include<iostream>
using namespace std;
int count1=0;
void printinfo(){
    if(count1==5){
        return;
    }
    cout<<"Hello world"<<endl;
    count1++;
    printinfo();
}
int main(){
    printinfo();
}

//print linearly 1 to n
/*#include<iostream>
using namespace std;
int count1=0;
void printinfo(int n){
    if(n==0){
        return;
    }
    count1++;
    cout<<count1<<endl;
    printinfo(n-1);
}
int main(){
    int n;
    cin>>n;
    printinfo(n);
}*/

//print from N to 1
/*#include<iostream>
using namespace std;
void printinfo(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    printinfo(n-1);
}
int main(){
    int n;
    cin>>n;
    printinfo(n);
}*/

//1 to n (backtrak)
/*#include<iostream>
using namespace std;
void function(int n,int i){
    if(n<1){
        return;
    }
    function(n-1,i); //generally we use n-1 to print in backward but we are using n-1 to print in forward by writing cout after the function call
    cout<<n<<endl;

}
int main(){
    int n;
    cin>>n;
    function(n,n);
}*/

//n to 1(back track)
/*#include<iostream>
using namespace std;
void function(int n,int i){
    if(n>i){
        return;
    }
    function(n+1,i);
    cout<<n<<endl;
}
int main(){
    int n;
    cin>>n;
    function(1,n);
}*/

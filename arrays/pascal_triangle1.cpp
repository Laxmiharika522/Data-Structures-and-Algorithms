//find the element in the pascal triangle if row and coloumn is given
//formula row-1
//            C 
 //            col-1
/*#include<iostream>
using namespace std;
int element(int row,int col){
    int n =row-1;
    int r = col -1;
    int res =1;
    for(int i=0;i<r;i++){
        res = res*(n-i);//nCr formula
        res = res/(i+1);
    }
    return res;
}
int main(){
    int row;
    int col;
    cin>>row;
    cin>>col;
    cout<<element(row,col);
}*/


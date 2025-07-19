////print the nth row of the pascal triangle
//TC----->O(N*R)
//SC----->O(1)
/*#include<iostream>
using namespace std;
int element(int row,int col){
    int n =row-1;
    int r = col -1;
    int res =1;
    for(int i=0;i<r;i++){//O(r)
        res = res*(n-i);//nCr formula
        res = res/(i+1);
    }
    return res;
}
int main(){
    int row;
    cin>>row;
    //in pascal tringle nth row has n elements . nelements means n columns 
    for(int i=1;i<=row;i++){//for(int i=0;i<col;i++) //O(N)
        cout<<element(row,i)<<" "; //printing element by element
    }
}*/

//fORMULA
//TC ----> O(N)
//SC ---->O(1)
/*#include<iostream>
using namespace std;
int main(){
    int row;
    cin>>row;
    int result =1;
    cout<<result<<" ";
    for(int i=1;i<row;i++){//1st element is always 1
        result = result * (row - i);
        result = result/i;
        cout<<result<<" ";
    }
}*/

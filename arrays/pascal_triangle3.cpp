//if n is given print the pascal triangle
#include<iostream>
#include<vector>
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
    int n;
    cin>>n;
    int row;
    int col;
    for(row = 1;row<=n;row++){//O(N^3) //nearly
        for(col=1;col<=row;col++){//nth row equal to n elements(n columns)
            cout<<(element(row,col))<<" ";
        }
        cout<<endl;
    }
}

//optimal 
//TC-----> O(N^2)
/*#include<iostream>
#include<vector>
using namespace std;
vector<int> pascalTriangle(int row){
        long long ans=1; //incase of bigger values
        vector<int>ansRow;
        ansRow.push_back(1);
        for(int col=1;col<row;col++){//O(N)
            ans =  ans *(row-col);
            ans = ans/(col);
            ansRow.push_back(ans);
        }
        return ansRow;
}
int main(){
    int n;
    cin>>n;
    for(int row=1;row<=n;row++){ //O(N)
        vector<int>result = pascalTriangle(row);
        //this for just printing
        for(int i: result){ //printing each and every row
            cout<<i<<" ";;
        }
        cout<<endl;
    }
}*/

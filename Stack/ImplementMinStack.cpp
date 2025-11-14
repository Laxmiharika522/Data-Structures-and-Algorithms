//in - built stack does not have getmin() function
//TC-->O(1)
//SC--->O(2N) //pair of stack data structure
#include<iostream>
#include<stack>
using namespace std;
class MinStack{
    stack<pair<int,int>>st; //we are storing value and minimum value
    public:
    void push(int x){
        int mini;
        if(st.empty()){
            mini = x;
        }else{
            mini = min(st.top().second,x);//second is the inbuilt function in pair <first,second>
        }
        st.push({x,mini});
    }
    void pop(){
        st.pop();
    }
    int top(){
        return st.top().first;
    }
    int getMin(){
        return st.top().second;
    }
    void getvalues(){
        stack<pair<int,int>> temp = st;
        cout << "Stack elements (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.top().first << " ";
            temp.pop();
        }
        cout << endl;
    }
};
int main(){
    MinStack m;
    m.push(12);
    m.push(24);
    m.push(35);
    m.push(56);
    m.push(7);
    m.push(14);
    cout<<"top element "<<m.top()<<endl; //14
    m.pop();
    m.pop();
    cout<<"Minimum element after pop "<<m.getMin()<<endl; //12
    m.pop();
    m.getvalues(); //35 24 12
}

//optimal solution
//TC --->O(1)
//SC--->O(N)//for stack
/*#include<iostream>
#include<stack>
using namespace std;
class MinStack{//MinStack is our customized stack
    stack<long long>st;
    long long mini;
    public:
    MinStack(){
        while(st.empty() ==  false){ //ensuring that stack is empty
            st.pop();
        }
        mini = INT_MAX;
    }
    void push(int value){
        long long val = value;
        if(st.empty()){
            mini = val;
            st.push(val);
        }else{
            if(val<mini){
                st.push(2*val-mini); //modified value is sent into stack and actual value is stored in mini
                mini = val;
            }else{
                st.push(val);
            }
        }
    }
    void pop(){
        if(st.empty()){
            return;
        }
        long long el = st.top();
        st.pop();
        if(el<mini){//that means popped element is minimum.so replace minimum with second minimum element
            mini = 2*mini - el;
        }
    }
    int top(){
        if(st.empty()){
            return -1;
        }
        long long el = st.top();
        if(el<mini){//these is the condition says that the elemnet we pushed in stack is modified element
            return mini;
        }else{
            return el;
        }
    }
    int getMin(){
        return mini;
    }
};
int main(){
    MinStack m;
    m.push(12);
    m.push(24);
    m.push(35);
    m.push(1);
    m.push(7);
    m.push(14);
    cout<<"top element "<<m.top()<<endl; //14
    m.pop();
    m.pop();
    cout<<"Minimum element after pop "<<m.getMin()<<endl; //1
    m.pop();
    cout<<"Minimum element after pop "<<m.getMin()<<endl; //12
}*/
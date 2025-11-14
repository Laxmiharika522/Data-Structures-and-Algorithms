//implementation of stack using using array
// Single operation (push, pop, top, size): O(1) → because it just touches one element.
// Entire program (with N pushes/pops in total): O(N) → because you may insert or remove up to N elements, so overall it scales with N.
// Space complexity: O(N) → because at most N elements are stored in the array.

//Drawback of arrays:
/* Fixed Size (Inflexible)
With a static array (int arr[1000];), the size must be known at compile time.
Even with a dynamic array (new int[size]), once allocated, you cannot change its size easily.
If your program needs more than size elements → overflow.
If you allocate too large, you waste memory.*/

#include<iostream>
using namespace std;
class Stack{
    int size;
    int *arr;//dynamically allocating but is of fixed size
    int top;
    public:
    Stack(){
        top =-1;
        size = 1000; //Size: Can be decided at runtime (e.g., user input).
        arr = new int[size]; //allocating size dynamically
    }
    void push(int x){
        top++;
        arr[top] = x;
    }
    int pop(){
        int x = arr[top];
        top--;
        return x;
    }
    int Top(){
        return arr[top];//dont increment or deccrement it
    }
    int Size(){
        return top+1;
    }
};
int main(){
    Stack s;//object creation
    s.push(6);
    s.push(10);
    s.push(23);
    cout<<"Top of stack before deleting any element "<<s.Top()<<endl;
    cout<<"Size of stack before deleting any element "<<s.Size()<<endl;
    cout<<"The element deleted is "<<s.pop()<<endl;
    cout<<"Top of stack after deleting any element "<<s.Top()<<endl;
    cout<<"Size of stack after deleting any element "<<s.Size()<<endl;
}
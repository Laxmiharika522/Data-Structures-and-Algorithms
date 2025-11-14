//Implement stack using Linkedlist
// The stack can be implemented in two ways:
// Statically:  Using arrays
// Dynamically: Using a linked list

/*Create a node for our new element.
Point to the next pointer of our element node to point to the head of the linked list.
Make the element node our top node.
Increment the size variable.*/

/*Check for underflow conditions in the stack.
Store the top node in a temp node and top node data in another variable.
Make the second node of our temp node a top.
Delete temp node.
Return the top node’s data.*/


/*When you create an object with new, it allocates memory on the heap (dynamic memory).
delete releases that memory back to the system, preventing memory leaks.*/

#include<iostream>
using namespace std;
struct stackNode{
    int data;
    stackNode *next; //pointer of type structNode
    int size;
    stackNode(int d){//structures can also have constructors which makes easy to initialize structure memebers
        data = d;
        next = NULL;
    }
};
struct stack{
    stackNode *top;//top is a pointer which points to the node
    int size;
    stack(){
        top=NULL;//initially pointing to null
        size =0;
    }
    void stackPush(int x){
        stackNode *element = new stackNode(x); //you must allocate memory dynamically for that new node using new
        element->next = top;
        top = element;
        cout << "Element pushed" << "\n";
        size++;
    }
    int stackPop(){
        if(top==NULL){
            return -1;
        }
        int topData = top->data;
        stackNode *temp = top; //temp is not a new node, it’s just a pointer variable that holds the address of the current top node.
        top = top->next;
        delete temp;
        size--;
        return topData;
    }
    int stackSize() {
        return size;
    }
    bool stackIsEmpty() {
        return top == NULL;
    }
    int stackPeek(){
        if(top==NULL){
            return -1;
        }else{
            return top->data;
        }
    }
    void printStack(){
        stackNode *current = top; //it is just a pointer of data type stackNode
        while(current!=NULL){
            cout<<current->data<<" ";
            current = current->next;
        }
    }
};
int main(){
    stack s;
    s.stackPush(10);
    cout << "Element popped: " << s.stackPop() << "\n"; //10
    cout << "Stack size: " << s.stackSize() << "\n"; //0
    cout <<"Stack empty or not? "<<s.stackIsEmpty()<<"\n"; //1
    cout << "stack's top element: " << s.stackPeek() << "\n"; //-1
}
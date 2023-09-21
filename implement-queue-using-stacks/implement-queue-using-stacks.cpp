#include<iostream>
#include<stack>

using namespace std;

class MyQueue {
public:
    stack<int> stack1 ;
    stack<int> stack2; 
    MyQueue() {
    }
    
    void push(int x) {
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }

        stack1.push(x);
        
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    
    int pop() {
        int value = stack2.top();
        stack2.pop();
        return value;
    }
    
    int peek() {
        return stack2.top();
        
    }
    
    bool empty() {
        return stack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(){
    MyQueue* obj = new MyQueue();
    obj->push(30);
    obj->push(40);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    cout << "Value: " << param_2 << " " << param_3 << " " << param_4;
    return 0;
}

#include<iostream>
#include<queue>

using namespace std;

class MyStack {
    priority_queue<pair<int, int>> queue1;
    int counter = 0;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        queue1.push({counter++, x});
    }
    
    int pop() {
        int temp = queue1.top().second;
        counter--;
        queue1.pop();
        return temp;
    }
    
    int top() {
        return queue1.top().second;
    }
    
    bool empty() {
        return queue1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(){
 MyStack* obj = new MyStack();
 obj->push(30);
 obj->push(40);
 int param_2 = obj->pop();
 int param_3 = obj->pop();
 bool param_4 = obj->empty();
 cout << "Value: " << param_2 << " " << param_3 << " " << param_4;
    return 0;
}

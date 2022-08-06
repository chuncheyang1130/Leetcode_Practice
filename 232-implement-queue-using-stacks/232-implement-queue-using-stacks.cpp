class MyQueue {
public:
    stack<int> container, reverse;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        container.push(x);
    }
    
    int pop() {
        while(!container.empty()){
            reverse.push(container.top());
            container.pop();
        }
        int num = reverse.top();
        reverse.pop();
        while(!reverse.empty()){
            container.push(reverse.top());
            reverse.pop();
        }
        return num;
    }
    
    int peek() {
        while(!container.empty()){
            reverse.push(container.top());
            container.pop();
        }
        int num = reverse.top();
        while(!reverse.empty()){
            container.push(reverse.top());
            reverse.pop();
        }
        return num;
    }
    
    bool empty() {
        return container.empty();
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
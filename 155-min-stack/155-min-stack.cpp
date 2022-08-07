class MinStack {
public:
    stack<int> st;
    map<int,int> table;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        table[val]++;
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        if(table[val] == 1){
            table.erase(val);
            return;
        }
        table[val]--;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return table.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
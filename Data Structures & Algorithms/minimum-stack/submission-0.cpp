class MinStack {
private:
    // Declare the stack as a class member so all functions can access it
    stack<pair<int, int>> st;

public:
    MinStack() {
    }
    
    void push(int val) {
        if (st.empty()) {
            // If it's the first element, it is both the value and the minimum
            st.push({val, val});
        } else {
            int current_min = min(val, st.top().second);
            st.push({val, current_min});
        }
    }
    
    void pop() {
        // It's good practice to ensure the stack isn't empty before popping
        if (!st.empty()) {
            st.pop();
        }
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

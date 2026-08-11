class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char c : s) {
            // If it's an opening bracket, push to stack
            if(c == '{' || c == '(' || c == '[') {
                st.push(c);
            }
            // If it's a closing bracket
            else {
                // If the stack is empty, there is no matching opening bracket
                if(st.empty()) {
                    return false;
                }
                
                // Check if the top of the stack matches the closing bracket
                if((c == '}' && st.top() == '{') || 
                   (c == ')' && st.top() == '(') || 
                   (c == ']' && st.top() == '[')) {
                    st.pop();
                } else {
                    // Mismatched brackets
                    return false; 
                }
            }
        }
        
        // If the stack is empty at the end, all brackets were matched
        return st.empty();
    }
};

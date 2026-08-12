class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n=temperatures.size();
        vector<int>nge(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && temperatures[st.top()]<=temperatures[i])st.pop();
            nge[i]=st.empty()?0:st.top()-i;
            st.push(i);
        }
        return nge;
    }
};

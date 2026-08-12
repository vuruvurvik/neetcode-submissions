class Solution {
    void findnse(vector<int>&h,vector<int>&nse)
    {
        stack<int>st;
        for(int i=h.size()-1;i>=0;i--)
        {
            while(!st.empty() && h[st.top()]>=h[i])st.pop();
            nse[i]=(!st.empty())?st.top():h.size();
            st.push(i);
        }
    }
    void findpse(vector<int>&h,vector<int>&pse)
    {
        stack<int>st;
        for(int i=0;i<h.size();i++)
        {
            while(!st.empty() && h[st.top()]>=h[i])st.pop();
            pse[i]=(!st.empty())?st.top():-1;
            st.push(i);
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>pse(n),nse(n);
        findnse(heights,nse);
        findpse(heights,pse);
        int maxarea=INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            int area=heights[i]*(nse[i]-pse[i]-1);
            maxarea=max(area,maxarea);
        }
        return maxarea;
    }
};

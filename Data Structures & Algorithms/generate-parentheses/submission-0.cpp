class Solution {
    void backtrack(vector<string>&ans,string res,int open,int close,int n)
    {
        if(int(res.size())==2*n)
        {
            ans.push_back(res);
            return;
        }
        if(open<n)
        {
            res.push_back('(');
            backtrack(ans,res,open+1,close,n);
            res.pop_back();
        }
        if(close<open)
        {
            res.push_back(')');
            backtrack(ans,res,open,close+1,n);
            res.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string res;
        res.reserve(2*n);
        backtrack(ans,res,0,0,n);
        return ans;
    }
};

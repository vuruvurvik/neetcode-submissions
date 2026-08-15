class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string>arr;
        string s;
        while(getline(ss,s,'/'))
        {
            if(s.empty() || s==".")continue;
            if(s=="..")
            {
                if(!arr.empty())arr.pop_back();
            }
            else
            arr.push_back(s);
        }
        string ans;
        for(auto it:arr)
        {
            ans+="/"+it;
        }
        return ans.empty()?"/":ans;
    }
};
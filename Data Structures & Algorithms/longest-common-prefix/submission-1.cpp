class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string str="";
        int i=0;
        while(i < strs[0].length() && i < strs[strs.size()-1].length() && strs[0][i]==strs[strs.size()-1][i])
        {
            str+=strs[0][i];
            i++;
        }
        return str;
    }
};
class Solution {
public:
    bool isPalindrome(string s) {
        string str1="";
        for(int i=0;i<s.size();i++)
        {
            if(!isalnum(s[i]))continue;
            str1+=tolower(s[i]);
        }
        string str=str1;
        reverse(str1.begin(),str1.end());
        return str==str1;
    }
};

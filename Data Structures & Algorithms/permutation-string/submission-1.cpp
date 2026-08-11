class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s1.size();
        if(k>s2.size())return false;
        vector<int>freq1(26,0);
        for(int i=0;i<s1.size();i++)freq1[s1[i]-'a']++;
        vector<int>freq2(26,0);
        for(int i=0;i<k;i++)
        {
            freq2[s2[i]-'a']++;
        }
        if(freq2==freq1)return true;
        for(int i=k;i<s2.size();i++)
        {
            freq2[s2[i]-'a']++;
            freq2[s2[i-k]-'a']--;
            if(freq2==freq1)return true;
        }
        return false;
    }
};

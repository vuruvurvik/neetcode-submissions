class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxfreq=0,ans=0;
        vector<int>freq(26,0);
        while(r<s.size())
        {
            freq[s[r]-'A']++;
            maxfreq=max(maxfreq,freq[s[r]-'A']);
            while((r-l+1)-maxfreq>k)
            {
                freq[s[l]-'A']--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};

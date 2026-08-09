class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());
        int maxcnt=0;
        for(int i=0;i<nums.size();i++)
        {
            int cnt=0;
            int conv;
            if(st.find(nums[i]-1)==st.end())
            {
                conv=nums[i];
                cnt=1;
            }
            while(st.find(conv+1)!=st.end())
            {
                cnt++;
                conv+=1;
            }
            maxcnt=max(cnt,maxcnt);
        }
        return maxcnt;
    }
};

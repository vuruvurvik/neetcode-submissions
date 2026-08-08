class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int me;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt==0)
            {
                me=nums[i];
                cnt=1;
            }
            if(nums[i]==me)cnt++;
            else cnt--;
        }
        int mcnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(me==nums[i])mcnt++;
        }
        if(nums.size()/2<mcnt)return me;
        else return -1;
    }
};
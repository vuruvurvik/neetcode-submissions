class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini=INT_MAX;
        int l=0,r=0,sum=0;
        while(r<nums.size())
        {
            sum+=nums[r];
            while(sum>=target)
            {
                mini=min(r-l+1,mini);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        if(mini==INT_MAX)return 0;
        else return mini;
    }
};
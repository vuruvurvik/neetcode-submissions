class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        vector<int>ans;
        vector<pair<int,int>>vec;
        for(auto it:mpp)
        {
            vec.push_back({it.second,it.first});
        }
        sort(vec.rbegin(),vec.rend());
        for(int i=0;i<k;i++)
        {
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};

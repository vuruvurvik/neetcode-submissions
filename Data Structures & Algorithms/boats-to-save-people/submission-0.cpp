class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(),p.end());
        int b=0;
        int l=0,r=p.size()-1;
        while(l<=r)
        {
            int curr=p[l]+p[r];
            if(curr<=limit){
                l++;
                r--;
            }
            else
            {
                r--;
            }
            b++;
        }
        return b;
    }
};
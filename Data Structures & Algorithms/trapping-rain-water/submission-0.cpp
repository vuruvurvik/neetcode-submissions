class Solution {
public:
    int trap(vector<int>& h) {
        int total=0;
        int n=h.size();
        vector<int>p(n);
        vector<int>s(n);
        p[0]=h[0];
        for(int i=1;i<n;i++)
        {
            p[i]=max(p[i-1],h[i]);
        }
        s[n-1]=h[n-1];
        for(int i=n-2;i>=0;i--)
        {
            s[i]=max(s[i+1],h[i]);
        }
        for(int i=0;i<n;i++)
        {
            total+=min(p[i],s[i])-h[i];
        }
        return total;
    }
};

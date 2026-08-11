class Solution {
public:
    int maxArea(vector<int>& h) {
        int area=0,maxarea=0;
        int l=0,r=h.size()-1;
        while(l<r)
        {
            int width=r-l;
            int height=min(h[l],h[r]);
            area=width*height;
            maxarea=max(area,maxarea);
            if(h[l]<h[r])l++;
            else r--;
        }
        return maxarea;
    }
};

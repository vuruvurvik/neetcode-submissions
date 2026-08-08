class Solution {
    void merge(int l,int mid,int r,vector<int>&nums)
    {
        int n1=mid-l+1;
        int n2=r-mid;
        vector<int>left(n1);
        vector<int>right(n2);
        for(int i=0;i<n1;i++)
        {
            left[i]=nums[l+i];
        }
        for(int i=0;i<n2;i++)
        {
            right[i]=nums[mid+i+1];
        }
        int i=0,j=0,k=l;
        while(i<n1 && j<n2)
        {
            if(left[i]<right[j])
            {
                nums[k]=left[i];
                i++;
                k++;
            }
            else
            {
                nums[k]=right[j];
                j++;
                k++;
            }
        }
        while(i<n1)
        {
            nums[k]=left[i];
            i++;
            k++;
        }
        while(j<n2)
        {
            nums[k]=right[j];
            j++;
            k++;
        }
    }
    void mergesort(int l,int r,vector<int>&nums)
    {
        if(l>=r)return;
        int mid=l+(r-l)/2;
        mergesort(l,mid,nums);
        mergesort(mid+1,r,nums);
        merge(l,mid,r,nums);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(0,nums.size()-1,nums);
        return nums;
    }
};
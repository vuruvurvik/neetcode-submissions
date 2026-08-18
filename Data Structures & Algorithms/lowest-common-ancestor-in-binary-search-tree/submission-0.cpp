/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    bool getpath(TreeNode* root,TreeNode *p,vector<TreeNode*>&arr)
    {
        if(root==nullptr)return false;
        arr.push_back(root);
        if(root==p)return true;
        if(getpath(root->left,p,arr) || getpath(root->right,p,arr))return true;
        arr.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>arr1,arr2;
        if(root==nullptr)return nullptr;
        getpath(root,p,arr1);
        getpath(root,q,arr2);
        TreeNode* ans;
        int n=arr1.size()<arr2.size()?arr1.size():arr2.size();
        for(int i=0;i<n;i++)
        {
            if(arr1[i]==arr2[i])ans=arr1[i];
        }
        return ans;
    }
};

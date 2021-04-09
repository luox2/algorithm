/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        vector<TreeNode*>out;
        helper(root, sum, 0, out, res);
        return res;
    }
    void helper(TreeNode*root, int sum, int cursum, vector<TreeNode*>&out, int &res){
        if(!root) return;
        cursum += root->val;
        out.push_back(root);
        if(cursum == sum) ++res;
        int t = cursum;
        for(int i = 0; i<out.size()-1; ++i){
            t -= out[i]->val;
            if(t==sum) ++res;
        }
        helper(root->left, sum, cursum, out, res);
        helper(root->right, sum, cursum, out, res);
        out.pop_back();
    }
};


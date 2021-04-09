/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>ret;
        while(!root){
            if(!root->left){
                ret.push_back(root->val);
                root = root->right;
            }
            else{
                TreeNode* pre = root->left;
                while(pre->right && pre->right!=root){
                    pre=pre->right;
                }
                if(!pre->right){
                    pre->right = root;
                    root = root->left;
                }else{
                    pre->right = NULL;
                    ret.push_back(root->val);
                    root = root->right;
                }
            }

        }
        return ret;

        
    }
};


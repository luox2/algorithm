/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructTree(nums, 0, nums.size()-1);
    }
    TreeNode* constructTree(vector<int>&nums, int i, int j){
        if(i>j) return NULL;
        int mid = i;
        for(int k = i+1; k<=j; ++k){
            if(nums[k]>nums[mid]){
                mid = k;
            }
        }
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = constructTree(i, mid-1);
        root->right = constructTree(mid+1, j);
        return root;
    }
};


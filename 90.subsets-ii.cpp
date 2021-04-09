/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        vector<int>out;
        dfs(nums, res, 0, out);
        return res;
    }
    void dfs(vector<int>&nums, vector<vector<int>>&res, int pos, vector<int>&out){
        res.push_back(out);
        for(int i = pos; i<nums.size(); ++i){
            out.push_back(nums[i]);
            dfs(nums, res, i+1, out);
            out.pop_back();
            while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        }
    }
};


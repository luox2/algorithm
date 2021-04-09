/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>out, visit(nums.size(), 0);
        sort(nums.begin(), nums.end());
        dfs(nums, res, out, visit, 0);
        return res;
    }
    void dfs(vector<int>&nums, vector<vector<int>>&res, vector<int>&out, vector<int>&visit, int level){
        if(level==nums.size()){
            res.push_back(out);
            return;
        }
        for(int i = 0; i<nums.size(); ++i){
            if(visit[i]==1) continue;
            if(i > 0 && nums[i]==nums[i-1] && visit[i-1]==0) continue;
            visit[i] = 1;
            out.push_back(nums[i]);
            dfs(nums, res, out, visit, level+1);
            out.pop_back();
            visit[i] = 0;
        }
    }
};


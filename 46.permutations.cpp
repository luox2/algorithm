/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>out, visited(nums.size(), 0);
        dfs(nums, res, out, 0, visited);
        return res;
    }
    void dfs(vector<int>& nums, vector<vector<int>>&res, vector<int>&out, vector<int>&visited, int level){
        if(level==nums.size()){
            res.push_back(out);
            return;
        }
        for(int i = 0; i<nums.size(); ++i){
            if(visited[i]==1) continue;
            visited[i] = 1;
            out.push_back(nums[i]);
            dfs(nums, res, out, level+1);
            out.pop_back();
            visited[i] = 0;
        }
    }
};


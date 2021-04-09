/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>out;
        dfs(candidates, res, out, 0, target);
        return res;
    }
    void dfs(vector<int>candidates,vector<vector<int>>&res, vector<int>&out, int start, int target){
        if(target<0) return;
        if(target==0){
            res.push_back(out);
            return;
        }
        for(int i = start; i<candidates.size(); ++i){
            out.push_back(candidates[i]);
            dfs(candidates, res, out, i, target-candidates[i]);
            out.pop_back();
        }
    }
};


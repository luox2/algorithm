/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>out;
        sort(candidates.begin(), candidates.end());
        dfs(candidates,res, out, 0, target);
        return res;
    }
    void dfs(vector<int>&candidates, vector<vector<int>>&res, vector<int>out, int start, int target){
        if(target<0) return;
        if(target==0){
            res.push_back(out);
            return;
        }
        for(int i = start; i<candidates.size(); ++i){
            if(i>start && candidates[i]==candidates[i-1]) continue;
            out.push_back(candidates[i]);
            dfs(candidates,res,out,i+1, target-candidates[i]);
            out.pop_back();
        }
    }
};


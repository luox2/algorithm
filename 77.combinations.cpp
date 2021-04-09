/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>out;
        dfs(res, out, n, k, 1);
        return res;
    }
    void dfs(vector<vector<int>>&res, vector<int>&out, int n, int k, int level){
        if(out.size()==k){
            res.push_back(out);
        }
        for(int i = level; i<=n; ++i){
            out.push_back(i);
            dfs(res,out,n, k, i+1);
            out.pop_back();
        }
    }
};


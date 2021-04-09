/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>res;
        vector<int>color(n, 0);
        for(int i = 0; i<n; ++i){
            if(dfs(graph, i, color)) res.push_back(i);
        }
        return res;
    }
    bool dfs(vector<vector<int>>& graph, int node, vector<int>&color){
        if(color[node]>0) return color[node]==2;
        // 
        color[node] = 1;
        for(auto i : graph[node]){
            if(color[i]==2) continue;
            if(color[i]==1 || !dfs(graph, i, color)) return false;
        }
        color[node] = 2;
        return true;
    }
};


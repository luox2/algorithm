/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>root(2001, -1);
        for(auto edge:edges){
            int x = find(root, edge[0]);
            int y = find(root, edge[1]);
            if(x==y) return edge;
            root[x] = y;
        }
        return {};
        
    }
    int find(vector<int>&root, int i){
        while(root[i]!=-1){
            i = root[i];
        }
        return i;
    }
};


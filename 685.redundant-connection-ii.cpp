/*
 * @lc app=leetcode id=685 lang=cpp
 *
 * [685] Redundant Connection II
 */
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // 初始化父节点 
        vector<int>root(n+1, 0), first, second;
        for(auto& edge:edges){
            if(root[edge[1]]==0){
                // 新边的第二个节点父节点是第一个节点
                root[edge[1]] = edge[0];
            }else{
                first = {root[edge[1]], edge[1]};
                second = edge;
                // 删掉这条边 
                edge[1] = 0;
                // 第二次出现的入度为2的边 
            }
        }

        for(int i = 0; i<=n; ++i){
            root[i] = i;
        }
        for(auto&edge:edges){
            if(edge[1]==0) continue;
            // 过滤刚才删掉的节点那条边
            int x = getRoot(root, edge[0]), y = getRoot(root, edge[1]);
            if(x==y){
                return first.empty()?edge:first;
            }
            root[y] = x;
            // 1->2 保存的是他的下一个位置
        }
        // 没有环存在的情况 
        return second;
        
    }
    int getRoot(vector<int>&root, int i){
        return i==root[i]?i:getRoot(root, root[i]);
    }
};


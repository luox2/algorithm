/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>>res;
        vector<vector<bool>>Pacific(m, vector<bool>(n, false));
        vector<vector<bool>>Atlantic(m, vector<bool>(n, false));

        for(int i = 0; i<m; ++i){
            dfs(matrix, Pacific, i, 0, INT_MIN);
            dfs(matrix, Atlantic, i, n-1, INT_MIN);
        }
        for(int i = 0; i<n; ++i){
            dfs(matrix, Pacific, 0, i, INT_MIN);
            dfs(matrix, Atlantic, m-1, i, INT_MIN);
        }
        for(int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                if(Atlantic[i][j]&&Pacific[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;

    }

    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>&visited, int i, int j, int pre){
        int m = matrix.size(), n = matrix[0].size();
        if(i<0||i>=m||j<0||j>=n||visited[i][j]||matrix[i][j]<pre) return;
        visited[i][j] = true;
        dfs(matrix, visited, i+1, j, matrix[i][j]);
        dfs(matrix, visited, i-1, j, matrix[i][j]);
        dfs(matrix, visited, i, j+1, matrix[i][j]);
        dfs(matrix, visited, i, j-1, matrix[i][j]);
    }
};


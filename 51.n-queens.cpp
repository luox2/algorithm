/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<int>queens(n, -1);
        dfs(0, res, queens);
        return res;
    }
    void dfs(int curRow, vector<vector<string>>&res, vector<int>&queens){
        int n = queens.size();
        if(curRow==n){
            vector<string>out(n, string(n, '.'));
            for(int i = 0; i<n; ++i){
                out[i][queens[i]] = 'Q';
            }
            res.push_back(out);
            return;
        }
        for(int i = 0; i<n; ++i){
            if(isValid(queens, curRow, i)){
                queens[curRow] = i; 
                dfs(curRow+1, res, queens);
                queens[curRow] = -1; 
            }
        }
    }
    bool isValid(vector<int>&queens, int row, int col){
        for(int i = 0; i<row; ++i){
            if(col == queens[i]||abs(row-i)==abs(col-queens[i])) return false;
        }
        return true;
    }
};


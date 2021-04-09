/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */
class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int>pos(n, -1);
        helper(pos, 0, res);
        return res;
    }
    void helper(vector<int>&pos, int row, int &res){
        int n = pos.size();
        if(row==n) ++res;
        for(int col = 0; col < n; ++col){
            if(isValid(pos, row, col)){
                pos[row] = col;
                helper(pos, row+1, res);
                pos[row] = -1;
            }
        }
    }
    bool isValid(vector<int>&pos, int row, int col){
        for(int i = 0; i<row; ++i){
            if(pos[i]==col || abs(pos[i]-col)==abs(i-row)){
                return false;
            }
        }
        return true;
    }
};


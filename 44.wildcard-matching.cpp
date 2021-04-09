/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>>dp(m+1, vector<bool>(n+1, false));
        // 表示 dp[i][j]表示前i个和前j个匹配值
        dp[0][0] = true;
        // 初始化一些条件 比如 s为空 
        for(int i = 1; i<=n; ++i){
            if(p[i-1]=='*') dp[0][i] = dp[0][i-1];
        } 
        for(int i = 1; i<=m; ++i){
            for(int j = 1; j<=n; ++j){
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j]||dp[i][j-1];
                }
                else{
                    dp[i][j] = (s[i-1]==p[j-1]||p[j-1]=='?') && dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
        
    }
};


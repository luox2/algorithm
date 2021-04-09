/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // dp[m+n] 表示s3的前m+n个字符可以由 s1和s2表示
        int m = s1.size(), n = s2.size();

        bool dp[m+1][n+1] = {0};
        dp[0][0] = true;

        // i = 0
        for(int j = 1; j < n+1; ++j){
            dp[0][j] = dp[0][j-1] & (s2[j-1] == s3[j-1]);
        }
        for(int i = 1; i < m+1; ++i){
            dp[i][0] = dp[i-1][0] & (s1[i-1] == s3[i-1]);
        }

        for(int i = 1; i < m+1; ++i){
            for(int j = 1; j < n+1; ++j){
                dp[i][j] = (dp[i-1][j] & (s1[i-1] == s3[i+j-1])) || (dp[i][j-1] & (s2[j-1] == s3[i+j-1]));
            }
        }

        return dp[m][n];   
    }
};
// @lc code=end


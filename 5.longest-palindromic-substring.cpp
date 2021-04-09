/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return s;
        int n = s.size(), left = 0, len = 1;
        int dp[n][n] = {0};
        for(int i = 0; i<n; ++i){
            dp[i][i] = 1;
            for(int j = 0; j<i; ++j){
                dp[i][j] = ((s[i]==s[j]) && (dp[i-1][j+1] || i-j<2));
                if(dp[i][j]){
                    if(i-j+1>len){
                        len = i-j+1;
                        left = j;
                    }
                }
            }
        }
        return s.substr(left, len);

    }
};


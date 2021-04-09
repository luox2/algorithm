/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <=1) return s;
        string res;
        int i = 0, n = s.size();
        vector<string> vec(numRows);
        while(i < n){
            for(int pos = 0; pos < numRows && i < n; ++pos){
                vec[pos] += s[i++];
            }
            for(int pos = numRows-2; pos > 0 && i<n; --pos){
                vec[pos] += s[i++];
            }
        }
        for(auto &a : vec) res += a;
        return res;
    }
};
// @lc code=end


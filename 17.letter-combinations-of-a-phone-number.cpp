/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string>res;
        vector<string>dict{"", "", };
        dfs(digits, res, dict, 0, "");
        return res;
    }
    void dfs(string digits, vector<string>&res, vector<string>dict, int level, string out){
        if(level == digits.size()){
            res.push_back(out);
            return;
        }
        string str = dict[digits[level]-'0'];
        for(int i = 0; i<str.size(); ++i){
            out += str[i];
            dfs(digits, res, dict, level+1, out);
        }
    }
};


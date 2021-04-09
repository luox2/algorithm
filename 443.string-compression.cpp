/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), cur = 0;
        for(int i = 0, j = 0; i<n; i=j){
            while(j<n && chars[j]==chars[i]) ++j;
            // a a b j = 2
            chars[cur++] = chars[i];
            if(j-i==1) continue;
            // a b 
            for(char c: to_string(j-i)) chars[cur++] = c;
        }
        return cur;
    }
};


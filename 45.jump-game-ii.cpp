/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, n = nums.size(), i = 0,cur = 0;
        while(cur < n-1){
            ++res;
            int pre = cur;
            for(; i<=pre; ++i){
                cur = max(cur, nums[i]+i);
            }
            if(pre==cur) return -1;
        }
        return res;
    }
};


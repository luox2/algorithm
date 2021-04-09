/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = left + (right-left)/2;
            int cnt = 0;
            for(auto i:nums){
                if(i<=mid) cnt++;
            }
            if(cnt<=mid){
                left = mid + 1;
            }else right = mid;
        }
        return right;
    }
};


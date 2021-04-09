/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = INT_MAX, res = 0;
        for(int price:prices){
            minp = min(minp, price);
            res = max(res, price-minp);
        }
        return res;
    }
};


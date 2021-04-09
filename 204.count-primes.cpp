/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */
class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool>prime(n, true);
        for(int i = 2; i < n; ++i){
            if(!prime[i]) continue;
            ++res;
            for(int j = 2; j*i<n; ++j){
                prime[i*j] = false;
            }
        }
        return res;
        
    }
};


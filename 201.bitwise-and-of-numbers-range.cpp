/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        // m,n 
        // m = 0001 n = 1000
        // 这个区间要看m到n中间最左边的数字是否相同
        while(m!=n){
            m>>=1;
            n>>=1;
            ++i;
        }
        return (m<<i);
        
    }
};


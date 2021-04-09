/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0; i<points.size(); ++i){
            map<pair<int, int>, int> m;
            int duplicate = 1;
            for(int j = i+1; j<points.size(); ++j){
                if(points[i][0]==points[j][0] && points[i][1] == points[j][1]){
                    duplicate++;
                    continue;
                }
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int d = gcd(dx, dy);
                ++m[{dx/d, dy/d}];
                // 比如 dx = 3, dy = 10
                // dy/dx = 3.333 
                // 存的3，10 比如x为0，0，y是3，10， z 6,20
            }
            res = max(res, duplicate);
            // 初始化了
            for(auto it=m.begin(); it!=m.end(); ++it){
                res = max(res, it->second+duplicate);
            } 
        }
        return res;
    }
    int gcd(int a, int b){
        return b==0?a:gcd(b, a%b);
    }
};


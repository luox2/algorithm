#
# @lc app=leetcode.cn id=93 lang=python3
#
# [93] 复原IP地址
#

# @lc code=start
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        self.res = []

        def is_valid(s):
            if len(s) == 0 or len(s) > 3 or (len(s) > 0 and s[0] == '0'): return False
            return True if 0 <= int(s) <= 255 else False 

        def helper(s, out, res, k):
            if k == 0:
                if len(s) == 0:
                    res.append(out)
                    # does need return
            else:
                # i == number of out
                for i in range(1, 4):
                    if len(s) >= i and is_valid(s[:i]):
                        if k == 1:
                            helper(s[i:], out + s[:i], res, k-1)
                        else:
                            helper(s[i:], out + s[:i] + '.', res, k-1)

        helper(s, "", self.res, 4)
        return self.res
# @lc code=end


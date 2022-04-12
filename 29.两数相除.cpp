// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem29.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int x, int y) {
        typedef long long LL;
        vector<LL> exp;
        bool is_minus = false;
        if(x > 0 && y < 0 || x < 0 && y > 0)
        {
            is_minus = true;
        }
        LL a = abs((LL)x), b = abs((LL)y);
        for(LL i = b; i <= a; i = i + i) exp.push_back(i);
        LL res = 0;
        for(int i = exp.size() - 1; i >= 0 ; i--)
        {
            if(a >= exp[i])
            {
                a -= exp[i];
                res += 1ll << i;
            }
        }
        if(is_minus) res = -res;
        if(res > INT_MAX || res < INT_MIN) return INT_MAX;
        return res;
    }
};
// @lc code=end


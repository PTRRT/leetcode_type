// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem32.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> stk;
        for(int i = 0,start = -1; i < s.size(); i++)
        {
            if(s[i] == '(') stk.push(i);
            else
            {
                if(!stk.empty())
                {
                    stk.pop();
                    if(!stk.empty())
                    {
                        res = max(res, i-stk.top());
                    }
                    else
                    {
                        res = max(res, i-start);
                    }
                }
                else{
                    start = i;
                }
            } 
        }
        return res;
    }
};
// @lc code=end


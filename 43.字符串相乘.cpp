// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem43.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> A, B;
        int n = num1.size(), m = num2.size();
        for(int i = n - 1; i >= 0; i--) A.push_back(num1[i] - '0');
        for(int j = m - 1; j >= 0; j--) B.push_back(num2[j] - '0');
        vector<int> C(m+n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                {
                    C[i+j] += A[i]*B[j];
                }
        for(int i = 0, t = 0; i < C.size(); i++)
        {
            t += C[i];
            C[i] = t % 10;
            t /= 10;
        }
        int k = C.size()-1;
        while(k > 0 && !C[k]) k--;
        string res;
        while(k >= 0) res += C[k--] + '0';
        return res;
    }
};
// @lc code=end


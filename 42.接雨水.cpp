// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] <= height[i]) {
                int top = st.top();
                st.pop();
                if (st.empty()) break;
                ans += (i - st.top() - 1) 
                        * (min(height[st.top()], height[i]) - height[top]);
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end


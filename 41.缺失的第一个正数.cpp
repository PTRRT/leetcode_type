// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem41.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 1;
        for(auto &x: nums)
        {
            if(x != INT_MIN) x--;
        }
        for(int i = 0; i < n; i++)
        {
           while(nums[i] < n && nums[i] >= 0 && nums[i] != nums[nums[i]] && nums[i] != i)
           {
               swap(nums[i], nums[nums[i]]);
           }
        }
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != i)
            return i+1;
        }
        return n+1;
    }
};
// @lc code=end


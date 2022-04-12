// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem31.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = nums.size()-1;
        while(k > 0 && nums[k-1] >= nums[k]) k--;
        if(k <= 0) reverse(nums.begin(), nums.end());
        else
        {
            int t = k;
            while(t < nums.size() && nums[k-1] < nums[t]) t++;
            swap(nums[t-1],nums[k-1]);
            reverse(nums.begin()+k,nums.end());
        }
    }
};
// @lc code=end


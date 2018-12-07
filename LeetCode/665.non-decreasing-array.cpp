/*
 * [665] Non-decreasing Array
 *
 * https://leetcode.com/problems/non-decreasing-array/description/
 *
 * algorithms
 * Easy (19.68%)
 * Total Accepted:    37.9K
 * Total Submissions: 192.4K
 * Testcase Example:  '[4,2,3]'
 *
 * 
 * Given an array with n integers, your task is to check if it could become
 * non-decreasing by modifying at most 1 element.
 * 
 * 
 * 
 * We define an array is non-decreasing if array[i]  holds for every i (1 
 * 
 * Example 1:
 * 
 * Input: [4,2,3]
 * Output: True
 * Explanation: You could modify the first 4 to 1 to get a non-decreasing
 * array.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [4,2,1]
 * Output: False
 * Explanation: You can't get a non-decreasing array by modify at most one
 * element.
 * 
 * 
 * 
 * Note:
 * The n belongs to [1, 10,000].
 * 
 */
class Solution {
public:
#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
    bool checkPossibility(vector<int>& nums) {
        int n =  nums.size();
        int *w = new int[n + 10];
        f(i, 0, n) w[i] = 20000;
        f(i, 0, n) *upper_bound(w, w + n, nums[i]) = nums[i];
        f(i, 0, n) if (w[i] == 20000) {
            delete []w;
            return i == n - 1;
        }
        delete []w;
        return 1;
    }
};

/*
 * [594] Longest Harmonious Subsequence
 *
 * https://leetcode.com/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (41.66%)
 * Total Accepted:    26.9K
 * Total Submissions: 64.5K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * We define a harmonious array is an array where the difference between its
 * maximum value and its minimum value is exactly 1.
 * 
 * Now, given an integer array, you need to find the length of its longest
 * harmonious subsequence among all its possible subsequences.
 * 
 * Example 1:
 * 
 * Input: [1,3,2,2,5,2,3,7]
 * Output: 5
 * Explanation: The longest harmonious subsequence is [3,2,2,2,3].
 * 
 * 
 * 
 * Note:
 * The length of the input array will not exceed 20,000.
 * 
 * 
 * 
 */
class Solution {
public:
    int findLHS(vector<int>& nums) {
        std::map<int, int> cnt;
        cnt.clear();
        for (auto x:nums) ++cnt[x];
        int mx = 0;
        for (auto x:nums) if (cnt[x]) {
            if (cnt[x - 1]) mx = std::max(mx, cnt[x] + cnt[x - 1]);
            if (cnt[x + 1]) mx = std::max(mx, cnt[x] + cnt[x + 1]);
        }
        return mx;
    }
};

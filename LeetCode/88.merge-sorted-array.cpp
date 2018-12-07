/*
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (33.98%)
 * Total Accepted:    299.3K
 * Total Submissions: 880.9K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::vector<int> tee;
        tee.reserve(m + n);
        nums1.reserve(m + n);
        int ll = 0, rr = 0;
        while (ll < m || rr < n) {
            if ((ll >= m) || (rr < n && nums2[rr] < nums1[ll])) {
                tee.push_back(nums2[rr++]);
            } else {
                tee.push_back(nums1[ll++]);
            }
        }
        nums1 = tee;
    }
};

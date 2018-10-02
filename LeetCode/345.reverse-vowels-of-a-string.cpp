/*
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (39.90%)
 * Total Accepted:    124.7K
 * Total Submissions: 312.6K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * Example 1:
 * 
 * 
 * Input: "hello"
 * Output: "holle"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "leetcode"
 * Output: "leotcede"
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 * 
 * 
 */
class Solution {
public:
    bool c(char x) {
        x = tolower(x);
        return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
    }
    string reverseVowels(string s) {
        string tee = "";
        for (auto x:s) if (c(x)) {
            tee += x;
        }
        int pos = 0;
        reverse(tee.begin(), tee.end());
        string res;
        for (auto x:s) {
            if (c(x)) {
                res += tee[pos++];
            } else {
                res += x;
            }
        }
        return res;
    }
};






/*
  Given a string s, find the length of the longest 
  substring
   without repeating characters.

  Example 1:

  Input: s = "abcabcbb"
  Output: 3
  Explanation: The answer is "abc", with the length of 3.
  
  Example 2:

  Input: s = "bbbbb"
  Output: 1
  Explanation: The answer is "b", with the length of 1.
  
  Example 3:
  Input: s = "pwwkew"
  Output: 3
  Explanation: The answer is "wke", with the length of 3.
  Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

  Constraints:

  0 <= s.length <= 5 * 104
  s consists of English letters, digits, symbols and spaces. 
  
  29-January-2023
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, len = 0;
        map<char, int> dict;
        for (int right=0; right<s.size(); right++) {
            if (dict.find(s[right]) != dict.end()) {
                left = max(left, dict[s[right]] + 1);
            }
            dict[s[right]] = right;
            len = max(len, right - left + 1);
        }
        return len;
    }
};



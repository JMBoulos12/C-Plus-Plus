



/*
  Write a function to find the longest common prefix string amongst an array of strings.

  If there is no common prefix, return an empty string "".

  Example 1:
  Input: strs = ["flower","flow","flight"]
  Output: "fl"
  
  Example 2:
  Input: strs = ["dog","racecar","car"]
  Output: ""
  Explanation: There is no common prefix among the input strings.

  Constraints:
  1 <= strs.length <= 200
  0 <= strs[i].length <= 200
  strs[i] consists of only lowercase English letters.
  
  02-February-2023
*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        string common = strs[0];
        char curr = strs[0][0];
        int size = strs.size();
        for (int i = 1; i<size; i++) {
            int idx = 0;
            int len = min(common.length(), strs[i].length());
            if (len < common.length()) {
                common = common.substr(0, len);
            }
            while (idx < len) {
                if (common[idx] != strs[i][idx]) {
                    common = common.substr(0, idx);
                }
                ++idx;
            }
        }
        return common;
    }
};

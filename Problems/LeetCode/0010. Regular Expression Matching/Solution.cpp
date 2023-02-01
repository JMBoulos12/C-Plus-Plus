



/*
  Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

  * '.' Matches any single character.
  * '*' Matches zero or more of the preceding element.
  * The matching should cover the entire input string (not partial).

  Example 1:
  Input: s = "aa", p = "a"
  Output: false
  Explanation: "a" does not match the entire string "aa".
  
  Example 2:
  Input: s = "aa", p = "a*"
  Output: true
  Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
  
  Example 3:
  Input: s = "ab", p = ".*"
  Output: true
  Explanation: ".*" means "zero or more (*) of any character (.)".

  Constraints:

  1 <= s.length <= 20
  1 <= p.length <= 30
  s contains only lowercase English letters.
  p contains only lowercase English letters, '.', and '*'.
  It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
  
  01-February-2023
*/

const int N = 100;
bool dp[N][N];
class Solution {
  public:
  bool isMatch(string s, string p)
  {
    memset(dp, 0, sizeof(dp[0][0]) * N * N);
    dp[s.length()][p.length()] = true;
    for (int i=s.length();i>=0;--i)
      for (int j=p.length() - 1;j>=0;--j)
      {
        if (p[j] == '*')
          dp[i][j] = false;
        else if (i == s.length()) // s[i:] is empty
        {
          if (j + 1 < p.length() && p[j + 1] == '*') // if p[j+1] exists and it is '*'
          {
            dp[i][j] = dp[i][j+2];
          }
          else
            dp[i][j] = false;
        }
        else // s[i:] is not empty
        {
          if (j + 1 < p.length() && p[j + 1] == '*') // if p[j+1] exists and it is '*'
          {
            if (s[i] == p[j] || p[j] == '.')
              dp[i][j] = dp[i][j+2] || dp[i + 1][j];
            else
              dp[i][j] = dp[i][j+2];
          }
          else
          {
            if (s[i] == p[j] || p[j] == '.')
              dp[i][j] = dp[i+1][j+1];
            else 
              dp[i][j] = false;
          }
        }
      }
    return dp[0][0];
  }
};

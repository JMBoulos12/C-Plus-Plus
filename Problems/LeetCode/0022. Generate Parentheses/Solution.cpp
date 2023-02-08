



/*
  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
  
  Example 1:
  Input: n = 3
  Output: ["((()))","(()())","(())()","()(())","()()()"]
  
  Example 2:
  Input: n = 1
  Output: ["()"]
  
  Constraints:
  1 <= n <= 8 
  07-February-2023
*/

.class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;

    dfs(n, n, "", ans);
    return ans;
  }

 private:
  void dfs(int l, int r, string&& path, vector<string>& ans) {
    if (l == 0 && r == 0) {
      ans.push_back(path);
      return;
    }

    if (l > 0) {
      path.push_back('(');
      dfs(l - 1, r, move(path), ans);
      path.pop_back();
    }
    if (l < r) {
      path.push_back(')');
      dfs(l, r - 1, move(path), ans);
      path.pop_back();
    }
  }
};

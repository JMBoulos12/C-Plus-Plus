



/*
  Given a signed 32-bit integer x, return x with its digits reversed. 
  If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

  A ssume the environment does not allow you to store 64-bit integers (signed or unsigned).

  Example 1:
  Input: x = 123
  Output: 321
  
  Example 2:
  Input: x = -123
  Output: -321
  
  Example 3:
  Input: x = 120
  Output: 21

  Constraints:
  -231 <= x <= 231 - 1 
  
  31-January-2023
*/


class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if(x < 0){
            neg = true;
            long long tmp = x * -1LL;
            //consider -2147483648
            if(tmp > INT_MAX) return 0;
            x = tmp;
        }
        
        int ans = 0;
        
        while(x){
            long long tmp = ans * 10LL + x % 10;
            //consider 1534236469
            if(tmp > INT_MAX) return 0;
            ans = tmp;
            x /= 10;
        }
        
        if(neg){
            ans *= -1;
        }
        
        return ans;
    }
};


// https://leetcode.com/problems/sqrtx/
// Time Complexity: O(log(N))
// Space Complexity: O(1)

class Solution {
public:
    int mySqrt(int x) {
        long result = x;
        
        while(result*result > x)
            result = (result + x/result) / 2;
        
        return result;
    }
};
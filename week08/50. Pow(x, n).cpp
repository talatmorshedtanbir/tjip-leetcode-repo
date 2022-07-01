// https://leetcode.com/problems/powx-n/
// Time Complexity: O(log(N))
// Space Complexity: O(1)

class Solution {
public:
    double myPow(double x, int n) { 
        if(n == 0)
            return 1;
        
        if(n<0) {
            x = 1/x;
        }
        
        double ans = 1;   
        while(n) {
            if(n%2 != 0)
                ans *=x;
            x *= x;
            n /= 2;
        }
        
        return ans;
    }
};
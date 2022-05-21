// https://leetcode.com/problems/ugly-number-ii/
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
public:
    int nthUglyNumber(int n) {
        vector <int> uglyNumbers (1,1);
        int i = 0, j = 0, k = 0;
        while (uglyNumbers.size() < n)
        {
            uglyNumbers.push_back(min(uglyNumbers[i] * 2, min(uglyNumbers[j] * 3, uglyNumbers[k] * 5)));
            
            if (uglyNumbers.back() == uglyNumbers[i] * 2)
                ++i;
            if (uglyNumbers.back() == uglyNumbers[j] * 3)
                ++j;
            if (uglyNumbers.back() == uglyNumbers[k] * 5)
                ++k;
        }
        
        return uglyNumbers.back();
    }
};
// https://leetcode.com/problems/first-bad-version/
// Time Complexity: O(log(N))
// Space Complexity: O(1)

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 0, end = n;
        
        while(start < end) {
            int mid = start+(end-start)/2;
                       
            if(!isBadVersion(mid))
                start = mid + 1;
            else
                end = mid;
        }
        
        return start;
    }
};
// https://leetcode.com/problems/non-overlapping-intervals/
// Time Complexity: O(N*log(N))
// Space Complexity: O(1)

bool comp(vector<int> &a,vector<int> &b) {
    return a[1]<b[1];
}

class Solution {

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int rmvCount = 0;
        sort(intervals.begin(), intervals.end(), comp);
        
        vector<int> prevInterval = intervals[0];
        for(int i=1; i<intervals.size(); i++) {
            if(prevInterval[1] > intervals[i][0]) {
                rmvCount++;
            }
            else {
                prevInterval = intervals[i];
            }
        }
        
        return rmvCount;
    }
};
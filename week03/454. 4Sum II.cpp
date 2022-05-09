// https://leetcode.com/problems/4sum-ii/

// Time Complexity: O(N^2)
// Space Complexity: O(N) 

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int>  twoSum;
        for(auto num1 : nums1) {
            for(auto num2 : nums2) {
                ++twoSum[num1+num2];
            }
        }
        
        int count = 0;
        for(auto num3 : nums3) {
            for(auto num4 : nums4) {
                auto it = twoSum.find(0 - (num3 + num4));
                if(it != twoSum.end()) {
                    count += it->second;
                }
            }
        }
        
        return count;
    }
};
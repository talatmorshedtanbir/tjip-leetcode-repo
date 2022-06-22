// https://leetcode.com/problems/find-peak-element/
// Time Complexity: O(log(N))
// Space Complexity: O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0, high=nums.size();
        
        while(low < high) {
            int mid=low+(high-low)/2;
            
            if(mid < nums.size()-1 && nums[mid] < nums[mid+1]) {
                low=mid+1;
            }
            else {
                high=mid;
            }
        }
        
        return low;
    }
};
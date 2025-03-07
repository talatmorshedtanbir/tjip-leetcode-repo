//Time Complexity - O(N)
//Space Complexity - O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int  right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        int trappedWater = 0;
        
        while(left < right) {
            if(leftMax < rightMax) {
                left++;
                leftMax = max(leftMax, height[left]);
                trappedWater += leftMax - height[left];
            }
            else {
                right--;
                rightMax = max(rightMax, height[right]);
                trappedWater += rightMax - height[right];
            }
        }
        
        return trappedWater;
    }
};
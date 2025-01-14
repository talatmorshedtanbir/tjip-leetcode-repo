//Time Complexity - O(N)
//Space Complexity - O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int elementCounts = nums.size();
    int position = 0;
    
    for(int i = 0; i < elementCounts; i++) {
        if(nums[i]!=0) {
            swap(nums[i], nums[position++]);
        }
    }
    }
};
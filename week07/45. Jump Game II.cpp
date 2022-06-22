// https://leetcode.com/problems/jump-game-ii/
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxJump = 0, currPos = 0, jump = 0;
        
        for(int i=0; i<nums.size()-1; i++) {
            maxJump = max(maxJump, i+nums[i]);

            if(i==currPos) {
                jump++;
                currPos = maxJump;
            }
        }
        
        return jump;
    }
};
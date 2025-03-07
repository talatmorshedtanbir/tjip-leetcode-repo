//Time Complexity - O(N)
//Space Complexity - O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
    
        for(auto num : nums) {
            ans ^= num;
        }

        return ans;
    }
};
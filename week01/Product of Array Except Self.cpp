//Time Complexity - O(N)
//Space Complexity - O(N)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> results(nums.begin(), nums.end());
        int arrayLength = nums.size();

        results[0] = 1;
        for(int i=1; i< arrayLength; i++) {
            results[i] = results[i-1]*nums[i-1];
        }

        int production = 1;
        for(int i = arrayLength-1; i>=0; i--) {
            results[i] = results[i]*production;
            production *= nums[i];
        }

        return results;
    }
};
//Time Complexity - O(N)
//Space Complexity - O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> answers;

    for(int i=0; i<nums.size(); i++){
        int complement = target - nums[i];
        if(answers.count(complement)) {
            return {answers[complement],i};
        }

        answers[nums[i]] = i;
    }

    return {};
    }
};
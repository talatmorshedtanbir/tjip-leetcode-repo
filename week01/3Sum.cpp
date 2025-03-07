//Time Complexity - O(N^2)
//Space Complexity - O(N)

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> results;
		sort(nums.begin(), nums.end());

		int length = nums.size() - 1;
		int left, right;
		for (int index = 0; index <= length; ++index)
		{
			if (index > 0 && nums[index - 1] == nums[index])
                continue;

			left = index + 1;
			right = length;

			while (left < right){
				if (nums[index] + nums[left] + nums[right] < 0)
                    left++;
				else if (nums[index] + nums[left] + nums[right] > 0)
                    right--;
				else {
					results.push_back({ nums[index], nums[left], nums[right] });
                    
                    left++;
					while ( left < right && nums[left] == nums[left - 1] )
                        left++;
				}
			}
		}
		return results;
	}
};
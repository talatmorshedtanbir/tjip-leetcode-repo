//Time Complexity - O(N)
//Space Complexity - O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        bool isGreater = false;
        int greaterIndex = 0;

        for(int k=len-1; k>0; k--){
            if(nums[k-1]<nums[k]){
                isGreater = true;
                greaterIndex = k-1;
                break;
            }
        }

        if(isGreater == false){
            reverse(nums.begin(), nums.end());
        }
        else{
            int i;
            for(i=len-1; i>greaterIndex; i--){
                if(nums[i]>nums[greaterIndex]){
                    break;
                }
            }

            swap(nums[i], nums[greaterIndex]);
            reverse(nums.begin()+greaterIndex+1, nums.end());
        }
    }
};
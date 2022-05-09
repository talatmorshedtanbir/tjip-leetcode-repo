//Time Complexity - O(N)
//Space Complexity - O(N)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> bucket(nums.begin(), nums.end());
        int longestSeq = 0;

        for(auto num: bucket) {
            if(bucket.count(num-1) == 0) {
                int nextNum = num + 1;
                while(bucket.count(nextNum) !=0) {
                    nextNum++;
                }

                longestSeq = max(longestSeq, nextNum-num);
            }
        }

        return longestSeq;
    }
};
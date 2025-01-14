//Time Complexity - O(N*log(N))
//Space Complexity - O(N)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        
	    for(int itr = 1; itr < k; itr++) {
            pq.pop();
        }
        
	    return pq.top();
    }
};
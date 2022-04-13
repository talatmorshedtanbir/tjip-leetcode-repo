//Time Complexity - O(N)
//Space Complexity - O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int winner, cnt=0;

    for(auto num: nums) {
       if(cnt) {

       cnt = winner == num? cnt+1 : cnt-1;
       }
       else {
        winner = num;
        cnt = 1;
       }
    }

    return winner;
    }
};
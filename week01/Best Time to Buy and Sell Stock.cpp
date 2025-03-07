//Time Complexity - O(N)
//Space Complexity - O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int minValue = INT_MAX;
    int profit = 0;

    for(int i=0; i< prices.size(); i++) {
        if(prices[i] < minValue) {
            minValue = prices[i];
        }

        int newProfit = prices[i]-minValue;
        if(newProfit > profit) {
            profit = prices[i]-minValue;
        }
    }

    return profit;
    }
};
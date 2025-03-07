//Time Complexity - O(N)
//Space Complexity - O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int minValue = INT_MAX;
    int totalProfit = 0;

    for(int i=0; i< prices.size(); i++) {
        if(prices[i] < minValue) {
            minValue = prices[i];
        }

        int profit = prices[i]-minValue;
        if(profit > 0) {
            minValue=prices[i];
            totalProfit += profit;
        }
    }

    return totalProfit;
    }
};
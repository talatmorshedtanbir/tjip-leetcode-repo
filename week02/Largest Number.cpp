// https://leetcode.com/problems/largest-number/
// Time Complexity: O(N*log(N))
// Space Complexity: O(N)

bool compare(string a,string b){
    return a+b > b+a;
}

class Solution {
public: 
    string largestNumber(vector<int>& nums) {
        vector<string> numToStrs;
        string answer = "";
        for(auto num: nums)
            numToStrs.push_back(to_string(num));

        sort(numToStrs.begin(), numToStrs.end(), compare);

        for(auto numToStr: numToStrs)
            answer += numToStr;

        if(answer[0]=='0')
            return "0";
        
        return answer;
    }
};
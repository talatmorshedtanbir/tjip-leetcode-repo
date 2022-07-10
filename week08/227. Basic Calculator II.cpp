// https://leetcode.com/problems/basic-calculator-ii/
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    int calculate(string& s) {
        int currValue = 0, ans = 0, tempValue = 0;
        char prevOperator = '+';
        s += "##";
        
        for(char ch : s)
            if(ch == ' ') 
                continue;
        
            else if(isdigit(ch)) 
                currValue = currValue * 10 + (ch-'0');
            else {
                if(prevOperator == '*')
                    tempValue *= currValue;
                else if(prevOperator == '/')
                    tempValue /= currValue;
                else                   
                    ans += tempValue,
                
                tempValue = prevOperator == '+' ? currValue : -currValue;
                prevOperator = ch;
                currValue = 0;
            }

        return ans;
    }
};
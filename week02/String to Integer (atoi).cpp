// https://leetcode.com/problems/string-to-integer-atoi/
// Time Complexity: O(NS)
// Space Complexity: O(1)

class Solution {
public:
    int myAtoi(string s) {
        long result = 0;
        int sign = 1;
        
        for(int i = 0; i<s.size();)
        {
            while(s[i] == ' ' && i<s.size())
                i++;
            
            if(s[i] == '-' || s[i] == '+')
            {
               sign = s[i++] == '-'? -1 : 1;
            }
            
            while('0'<= s[i] && s[i] <= '9') 
            {
                result = result*10 + (s[i++]-'0');
                
                if(result*sign >= INT_MAX)
                    return INT_MAX;
                if(result*sign <= INT_MIN) 
                    return INT_MIN;                
            }
            
            return result*sign;
        }
        
        return result;
    }
};
// https://leetcode.com/problems/roman-to-integer/
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
public:
    unordered_map<char, int> mapValues = {
        {'M', 1000}, 
        {'D', 500}, 
        {'C', 100}, 
        {'L', 50}, 
        {'X', 10}, 
        {'V', 5}, 
        {'I', 1}
    };
    
    int romanToInt(string s) {
        int result = 0;
        
        for(int i=0; i< s.length(); i++){
            if(mapValues[s[i]] < mapValues[s[i+1]]){
                result -= mapValues[s[i]];
            }
            else{
                result += mapValues[s[i]];
            }
        }
        
        return result;
    }
};
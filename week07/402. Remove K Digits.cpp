// https://leetcode.com/problems/remove-k-digits/
// Time Complexity: O(N*K) //K is for removing larger digits
// Space Complexity: O(1)

class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;        
        int totalNums = num.size();
        int keep = totalNums-k;
        
        for (int i=0; i<totalNums; i++) {
            while (result.size()>0 && result.back()>num[i] && k>0) {
                result.pop_back();
                k--;
            }
            
            result.push_back(num[i]);
            
            if(result.size() == 1 && num[i] == '0') {
                result.pop_back();
            }      
        }
        
        while(k && result.size() != 0) {
            result.pop_back();
            k--;
        }
        
        return result == "" ? "0" : result;
    }
};
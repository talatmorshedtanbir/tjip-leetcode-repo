// https://leetcode.com/problems/isomorphic-strings/
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> sMap(0);
        unordered_map<char,int> tMap(0);
        
        if(s.length() != t.length()){
            return false;
        }
        
        for(int i=0; i<t.length(); i++){
            if(sMap[s[i]] != tMap[t[i]]){
                return false;
            }
            else{
                sMap[s[i]] = i+1;
                tMap[t[i]] = i+1;
            }
        }
        
        return true;
    }
};
// https://leetcode.com/problems/group-anagrams/
// Time Complexity: O(N*log(M))
// Memory Complexity: O(N + M)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramsMap;
        vector<vector<string>> anagrams;
        
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            anagramsMap[t].push_back(s);
        }
        
        for (auto p : anagramsMap) { 
            anagrams.push_back(p.second);
        }
        
        return anagrams;
    }
};
// https://leetcode.com/problems/word-break/
// Time Complexity: O(N*M*K)
// Spcae Complexity: O(N)

class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        vector<bool> wordMatched(s.length(), false);        
        wordMatched[0] = true;
        
        for(int i = 1; i <= s.length(); i++){
            for(string word: dict){
                int wordLen = word.length();
                if(wordLen <= i){
                    if(wordMatched[i - wordLen]){
                        if(word == s.substr(i-wordLen, wordLen)){                
                            wordMatched[i] = true;
                            break;
                        }
                    }
                }
            }
        }

        return wordMatched[s.length()];
    }
};
// https://leetcode.com/problems/number-of-matching-subsequences/
// Time Complexity: O(N*log(N))
// Space Complexity: O(1)

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> trackChar(26);
        int result = 0;

        for(int i=0; i<s.size(); i++)
            trackChar[s[i]-'a'].push_back(i);

        for(auto word: words){
            int pos = -1;
            bool isFound = true;

            for(char ch: word){
                auto it = upper_bound(trackChar[ch-'a'].begin(), trackChar[ch-'a'].end(), pos);
                if(it == trackChar[ch-'a'].end())
                    isFound = false;
                else 
                    pos = *it;
            }

            if(isFound)
                result++;
        }

        return result;    
    }
};
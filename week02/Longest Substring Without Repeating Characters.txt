class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256,-1);
        int maxLen = 0,start = -1;

        for(int i=0; i<s.length(); i++) {
            if(freq[s[i]] > start){
                start = freq[s[i]];
            }
            freq[s[i]] = i;

            maxLen = max(maxLen,i-start);
        }

        return maxLen;
    }
};
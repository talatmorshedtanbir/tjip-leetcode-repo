class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        if(len1 != len2)
            return false;
        
        vector<int> freq(256, 0);
        
        for(int i=0; i<len1; i++) {
            freq[s[i]]++;
            freq[t[i]]--;
        }
        
        for(int i=0; i<len1; i++){
            if(freq[s[i]])
                return false;
        }
        
        return true;
    }
};
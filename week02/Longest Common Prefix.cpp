class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";

        string prefix = strs[0];
        int i=1;
        while(i<strs.size())
        {
            while(strs[i].find(prefix) != 0)
                prefix = prefix.substr(0, prefix.size()-1);
            i++;
        }

        return prefix;
    }
};
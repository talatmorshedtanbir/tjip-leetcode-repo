// https://leetcode.com/problems/find-and-replace-in-string/
// Time Complexity: O(SN)
// Space Complexity: O(N)

class Solution {
public:
string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
    vector<pair<int, int>> mapIndices;

    for (int i = 0 ; i < indices.size(); i++)
        mapIndices.push_back({indices[i], i});

    sort(mapIndices.rbegin(), mapIndices.rend());

    for (auto indx : mapIndices) {
        int i = indx.first;
        string str = sources[indx.second], targetStr = targets[indx.second];
        if (s.substr(i, str.length()) == str)
            s = s.substr(0, i) + targetStr + s.substr(i + str.length());
    }
    
    return s;
}
};
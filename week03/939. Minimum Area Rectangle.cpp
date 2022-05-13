// https://leetcode.com/problems/minimum-area-rectangle/
// Time Complexity: O(N^2)
// Space Complexity: O(N)

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ans = INT_MAX;
        unordered_map<int, unordered_set<int>> mymap;
        
        for (auto p : points) {
            mymap[p[0]].insert(p[1]);
        }
        
        for (int i = 0; i < points.size(); i++) {
            for (int j = i+1; j < points.size(); j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                if (abs(x1-x2) == 0 || abs(x1-x2) != abs(y1-y2))
                    continue;

                ans += cntPoints[x1][y2] * cntPoints[x2][y1];
            }
        }

        return ((ans == INT_MAX) ? 0: ans);
    }
};
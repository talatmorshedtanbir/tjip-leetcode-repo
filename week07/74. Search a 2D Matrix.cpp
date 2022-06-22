// https://leetcode.com/problems/search-a-2d-matrix/
// Time Complexity: O(log(N))
// Space Complexity: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, col = matrix[0].size()-1;
        
        while(row < matrix.size() && col >= 0) {
            if(matrix[row][col] == target)
                return true;
            
            if(matrix[row][col] > target)
                col--;
            else
                row++;
        }
        
        return false;
    }
};
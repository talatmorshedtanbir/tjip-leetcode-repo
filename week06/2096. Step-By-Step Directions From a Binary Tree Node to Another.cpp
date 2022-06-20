// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
// Time Complexity: O(N+N+M) M for String Reverse
// Spcae Complexity: O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool find(TreeNode* node, int val, string &path) {
        if (node->val == val)
            return true;
        
        if (node->left && find(node->left, val, path))
            path.push_back('L');
        
        else if (node->right && find(node->right, val, path))
            path.push_back('R');
        
        return !path.empty();
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, desPath;
        
        find(root, startValue, startPath);
        find(root, destValue, desPath);

        while (!startPath.empty() && !desPath.empty() && startPath.back() == desPath.back()) {
            startPath.pop_back();
            desPath.pop_back();
        }
        
        return string(startPath.size(), 'U') + string(rbegin(desPath), rend(desPath));
    }
};
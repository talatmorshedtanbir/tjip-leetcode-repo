// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Time Complexity: O(N) 
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
    int maxPath = INT_MIN;
public:  
    int calculatePathSum(TreeNode* root) {
        if (root == NULL) 
            return 0;
        
        int left = max(calculatePathSum(root->left), 0);
        int right = max(calculatePathSum(root->right), 0);
        
        maxPath = max(maxPath, root->val + left + right);
        
        return root->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        calculatePathSum(root);
        
        return maxPath;
    }
};
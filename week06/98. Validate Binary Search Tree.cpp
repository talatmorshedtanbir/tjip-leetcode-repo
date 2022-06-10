// https://leetcode.com/problems/validate-binary-search-tree/
// Time Complexity: O(N) 
// Space Complexity: O(N)

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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> nodes;
        TreeNode* prevNode = NULL;
        
        while(root != NULL || !nodes.empty()) {
            while(root != NULL) {
                nodes.push(root);
                root = root->left;
            }
            
            root = nodes.top();
            nodes.pop();
            
            if(prevNode != NULL && root->val <= prevNode->val) {
                return false;
            } 
            
            prevNode = root;
            root = root->right;
        }
        
        return true;
    }   
};
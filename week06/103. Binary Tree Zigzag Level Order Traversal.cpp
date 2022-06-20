// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Time Complexity: O(N) 
// Space Complexity: O(N+M)

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        
        vector<vector<int>> results;
        queue<TreeNode*> nodes;
        bool isLevelEven = true;
        nodes.push(root);
        
        while(!nodes.empty()) {
            int qSize = nodes.size();
            vector<int> currLevelNodes(qSize);
            
            for(int i=0; i<qSize; i++) {
                TreeNode* currNode = nodes.front();
                nodes.pop();
                
                if(isLevelEven) {
                    currLevelNodes[i] = currNode->val;
                }
                else {
                    currLevelNodes[qSize-i-1] = currNode->val;
                }              
                
                if(currNode->left)
                    nodes.push(currNode->left);
                
                if(currNode->right)
                    nodes.push(currNode->right);
            }
            
            results.emplace_back(currLevelNodes);
            isLevelEven = !isLevelEven;
        }
        
        return results;
    }
};
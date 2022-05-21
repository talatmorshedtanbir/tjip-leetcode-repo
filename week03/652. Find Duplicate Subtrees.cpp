// https://leetcode.com/problems/find-duplicate-subtrees/
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
    vector<TreeNode*> answers;
    unordered_map<string,int> mp;

    string traverse(TreeNode* root){
        if(root == NULL) 
            return "-";
            
        string left = traverse(root->left);
        string right = traverse(root->right);
        string str = to_string(root->val) +"-"+left+"-"+right;

        if(mp[str]==1){
            answers.push_back(root);
        }

        mp[str]++;
        return str;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root) 
            return answers;

        traverse(root);

        return answers;
    }
};
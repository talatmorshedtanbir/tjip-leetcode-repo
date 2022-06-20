// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
int cnt = 0;
int ans = 0;
    
void inOrder(TreeNode* root){
    if(root == NULL)
        return;

    inOrder(root->left);
    
    cnt--;
    if(cnt == 0)
        ans = root->val;
    
    inOrder(root->right);
}
    
public:
    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        inOrder(root);

        return ans;
    }
};
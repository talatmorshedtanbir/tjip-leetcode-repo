// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Time Complexity: O(N) 
// Spcae Complexity: O(logN)

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
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end){
        if(end<=start)
            return NULL; 
        
        int mid=(end+start)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        
        root->left = sortedArrayToBST(nums, start, mid);
        root->right = sortedArrayToBST(nums, mid+1, end);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
};